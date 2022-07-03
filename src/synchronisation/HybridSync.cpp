#include "../headers/synchronisation/HybridSync.h"

using namespace HybridGGPO;

HybridSync::HybridSync(UdpMsg::connect_status* connect_status) :
    _local_connect_status(connect_status),
    _input_queues(NULL)
{
    _framecount = 0;
    _last_confirmed_frame = -1;
    _max_prediction_frames = 0;
    memset(&_savedstate, 0, sizeof(_savedstate));
}

HybridSync::~HybridSync()
{
    /*
     * Delete frames manually here rather than in a destructor of the SavedFrame
     * structure so we can efficently copy frames via weak references.
     */
    for (int i = 0; i < ARRAY_SIZE(_savedstate.frames); i++) {
        _callbacks.free_buffer(_savedstate.frames[i].buf);
    }
    delete[] _input_queues;
    _input_queues = NULL;
}

void
HybridSync::Init(
        HybridSync::Config& config,
        IInputPredictionStrategyService* inputPredictionStrategy
)
{
    _config = config;
    _callbacks = config.callbacks;
    _framecount = 0;
    _rollingback = false;

    _max_prediction_frames = config.num_prediction_frames;

    CreateQueues(config);

    if (_inputPredictionStrategy) {
        // TD: Add onRemoved callback to IInputPredictionStrategyService
    }

    _inputPredictionStrategy = inputPredictionStrategy;

    // TD: Add onInitialized callback to IInputPredictionStrategyService
}

void
HybridSync::SetLastConfirmedFrame(int frame)
{
    _last_confirmed_frame = frame;
    if (_last_confirmed_frame > 0) {
        for (int i = 0; i < _config.num_players; i++) {
            _input_queues[i].DiscardConfirmedFrames(frame - 1);
        }
    }
}

bool
HybridSync::AddLocalInput(int queue, GameInput& input)
{
    int frames_behind = _framecount - _last_confirmed_frame;
    if (_framecount >= _max_prediction_frames && frames_behind >= _max_prediction_frames) {
        Log("Rejecting input from emulator: reached prediction barrier.\n");
        return false;
    }

    if (_framecount == 0) {
        SaveCurrentFrame();
    }

    Log("Sending undelayed local frame %d to queue %d.\n", _framecount, queue);
    input.frame = _framecount;
    _input_queues[queue].AddInput(input);

    return true;
}

void
HybridSync::AddRemoteInput(int queue, GameInput& input)
{
    _input_queues[queue].AddInput(input);
}

int
HybridSync::GetConfirmedInputs(void* values, int size, int frame)
{
    int disconnect_flags = 0;
    char* output = (char*)values;

    ASSERT(size >= _config.num_players * _config.input_size);

    memset(output, 0, size);
    for (int i = 0; i < _config.num_players; i++) {
        GameInput input;
        if (_local_connect_status[i].disconnected && frame > _local_connect_status[i].last_frame) {
            disconnect_flags |= (1 << i);
            input.erase();
        }
        else {
            _input_queues[i].GetConfirmedInput(frame, &input);
        }
        memcpy(output + (i * _config.input_size), input.bits, _config.input_size);
    }
    return disconnect_flags;
}

int
HybridSync::SynchronizeInputs(void* values, int size)
{
    int disconnect_flags = 0;
    char* output = (char*)values;

    ASSERT(size >= _config.num_players * _config.input_size);
    
    memset(output, 0, size);
    for (int i = 0; i < _config.num_players; i++) {
        GameInput input;
        if (_local_connect_status[i].disconnected && _framecount > _local_connect_status[i].last_frame) {
            disconnect_flags |= (1 << i);
            input.erase();
        }
        // InputQueue.GetInput(...) returns false when predicting
        else if (!_input_queues[i].GetInput(_framecount, &input)) {
            // TODO : Find a better method to retrieve state or let the strategy manage the state indexing
            SavedFrame* state = _savedstate.frames + FindSavedFrameIndex(_framecount);
            
            ASSERT(state->buf && state->cbuf);

            // We use the given input prediction strategy
            _inputPredictionStrategy->requestPrediction(_framecount, (char const*)state->buf, (void*)input.bits, input.size);
        }
        memcpy(output + (i * _config.input_size), input.bits, _config.input_size);
    }
    return disconnect_flags;
}

void
HybridSync::CheckSimulation(int timeout)
{
    int seek_to;
    if (!CheckSimulationConsistency(&seek_to)) {
        AdjustSimulation(seek_to);
    }
}

void
HybridSync::IncrementFrame(void)
{
    _framecount++;
    SaveCurrentFrame();
}

void
HybridSync::AdjustSimulation(int seek_to)
{
    int framecount = _framecount;
    int count = _framecount - seek_to;

    Log("Catching up\n");
    _rollingback = true;

    /*
     * Flush our input queue and load the last frame.
     */
    LoadFrame(seek_to);
    ASSERT(_framecount == seek_to);

    /*
     * Advance frame by frame (stuffing notifications back to
     * the master).
     */
    ResetPrediction(_framecount);
    for (int i = 0; i < count; i++) {
        _callbacks.advance_frame(0);
    }
    ASSERT(_framecount == framecount);

    _rollingback = false;

    Log("---\n");
}

void
HybridSync::LoadFrame(int frame)
{
    // find the frame in question
    if (frame == _framecount) {
        Log("Skipping NOP.\n");
        return;
    }

    // Move the head pointer back and load it up
    _savedstate.head = FindSavedFrameIndex(frame);
    SavedFrame* state = _savedstate.frames + _savedstate.head;

    Log("=== Loading frame info %d (size: %d  checksum: %08x).\n",
        state->frame, state->cbuf, state->checksum);

    ASSERT(state->buf && state->cbuf);
    _callbacks.load_game_state(state->buf, state->cbuf);

    // Reset framecount and the head of the state ring-buffer to point in
    // advance of the current frame (as if we had just finished executing it).
    _framecount = state->frame;
    _savedstate.head = (_savedstate.head + 1) % ARRAY_SIZE(_savedstate.frames);
}

void
HybridSync::SaveCurrentFrame()
{
    /*
     * See StateCompress for the real save feature implemented by FinalBurn.
     * Write everything into the head, then advance the head pointer.
     */
    SavedFrame* state = _savedstate.frames + _savedstate.head;
    if (state->buf) {
        _callbacks.free_buffer(state->buf);
        state->buf = NULL;
    }
    state->frame = _framecount;
    _callbacks.save_game_state(&state->buf, &state->cbuf, &state->checksum, state->frame);

    Log("=== Saved frame info %d (size: %d  checksum: %08x).\n", state->frame, state->cbuf, state->checksum);
    _savedstate.head = (_savedstate.head + 1) % ARRAY_SIZE(_savedstate.frames);
}

HybridSync::SavedFrame&
HybridSync::GetLastSavedFrame()
{
    int i = _savedstate.head - 1;
    if (i < 0) {
        i = ARRAY_SIZE(_savedstate.frames) - 1;
    }
    return _savedstate.frames[i];
}


int
HybridSync::FindSavedFrameIndex(int frame)
{
    int i, count = ARRAY_SIZE(_savedstate.frames);
    for (i = 0; i < count; i++) {
        if (_savedstate.frames[i].frame == frame) {
            break;
        }
    }
    if (i == count) {
        ASSERT(FALSE);
    }
    return i;
}


bool
HybridSync::CreateQueues(Config& config)
{
    delete[] _input_queues;
    _input_queues = new InputQueue[_config.num_players];

    for (int i = 0; i < _config.num_players; i++) {
        _input_queues[i].Init(i, _config.input_size);
    }
    return true;
}

bool
HybridSync::CheckSimulationConsistency(int* seekTo)
{
    int first_incorrect = GameInput::NullFrame;
    for (int i = 0; i < _config.num_players; i++) {
        int incorrect = _input_queues[i].GetFirstIncorrectFrame();
        Log("considering incorrect frame %d reported by queue %d.\n", incorrect, i);

        if (incorrect != GameInput::NullFrame && (first_incorrect == GameInput::NullFrame || incorrect < first_incorrect)) {
            first_incorrect = incorrect;
        }
    }

    if (first_incorrect == GameInput::NullFrame) {
        Log("prediction ok.  proceeding.\n");
        return true;
    }
    *seekTo = first_incorrect;
    return false;
}

void
HybridSync::SetFrameDelay(int queue, int delay)
{
    _input_queues[queue].SetFrameDelay(delay);
}


void
HybridSync::ResetPrediction(int frameNumber)
{
    for (int i = 0; i < _config.num_players; i++) {
        _input_queues[i].ResetPrediction(frameNumber);
    }
}


bool
HybridSync::GetEvent(Event& e)
{
    if (_event_queue.size()) {
        e = _event_queue.front();
        _event_queue.pop();
        return true;
    }
    return false;
}

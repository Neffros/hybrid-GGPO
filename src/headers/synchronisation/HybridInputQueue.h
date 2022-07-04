#pragma once

#include "game_input.h"
#include "service/strategy/IInputPredictionStrategyService.h"

#define INPUT_QUEUE_LENGTH    128
#define DEFAULT_INPUT_SIZE      4

namespace HybridGGPO
{
    /// <summary>
    /// HybridGGPO authors' note:
    /// Literally the Sync class from GGPO using prediction strategy when a player's input queue is predicting
    /// </summary>
    class HybridInputQueue {
    public:
        HybridInputQueue(int input_size = DEFAULT_INPUT_SIZE);
        ~HybridInputQueue();

    public:
        void Init(int id, int input_size);
        int GetLastConfirmedFrame();
        int GetFirstIncorrectFrame();
        int GetLength() { return _length; }

        void SetFrameDelay(int delay) { _frame_delay = delay; }
        void ResetPrediction(int frame);
        void DiscardConfirmedFrames(int frame);
        bool GetConfirmedInput(int frame, GameInput* input);
        bool GetInput(int frame, GameInput* input, void* values, int player, IInputPredictionStrategyService* strategy);
        void AddInput(GameInput& input);

    protected:
        int AdvanceQueueHead(int frame);
        void AddDelayedInputToQueue(GameInput& input, int i);
        void Log(const char* fmt, ...);

    protected:
        int                  _id;
        int                  _head;
        int                  _tail;
        int                  _length;
        bool                 _first_frame;

        int                  _last_user_added_frame;
        int                  _last_added_frame;
        int                  _first_incorrect_frame;
        int                  _last_frame_requested;

        int                  _frame_delay;

        GameInput            _inputs[INPUT_QUEUE_LENGTH];
        GameInput            _prediction;
    };
}

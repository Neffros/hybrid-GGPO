#pragma once

#include "game_input.h"
#include <service/HybridGGPOServiceProvider.h>

#define INPUT_QUEUE_LENGTH    128
#define DEFAULT_INPUT_SIZE      4

namespace HybridGGPO
{
    /// <summary>
    /// HybridGGPO authors' note:
    /// Literally the InputQueue class from GGPO receiving HybridGGPO's service provider at initialization
    /// and using user prediction strategy instead of naive prediction
    /// </summary>
    class HybridInputQueue {
    public:
        HybridInputQueue();
        ~HybridInputQueue();

    public:
        void Init(int id, int input_size, HybridGGPOServiceProvider* serviceProvider);
        int GetLastConfirmedFrame();
        int GetFirstIncorrectFrame();
        int GetLength() { return _length; }

        void SetFrameDelay(int delay) { _frame_delay = delay; }
        void ResetPrediction(int frame);
        void DiscardConfirmedFrames(int frame);
        bool GetConfirmedInput(int frame, GameInput* input);
        bool GetInput(int frame, GameInput* input, void* values, int player, int size);
        void AddInput(GameInput& input);

    protected:
        int AdvanceQueueHead(int frame);
        void AddDelayedInputToQueue(GameInput& input, int i);
        void Log(const char* fmt, ...);

    protected:
        HybridGGPOServiceProvider*  _serviceProvider;

        int                         _id;
        int                         _head;
        int                         _tail;
        int                         _length;
        bool                        _first_frame;

        int                         _last_user_added_frame;
        int                         _last_added_frame;
        int                         _first_incorrect_frame;
        int                         _last_frame_requested;

        int                         _frame_delay;

        GameInput                   _inputs[INPUT_QUEUE_LENGTH];
        GameInput                   _prediction;
    };
}

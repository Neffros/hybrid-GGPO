#pragma once

#include "game_input.h"

// Interface to create the base of a prediction strategy.
struct IInputPredictionStrategy
{
    // Called upon advancing a frame of the game
    virtual void onFrameAdvanced(int frame, char const* buffer, void* values, int size) = 0;

    // When GGPO can't retrieve an input, request a prediction from the strategy
    virtual void requestPrediction(int requestedFrame, char const* buffer, void* values, int size) = 0;
};
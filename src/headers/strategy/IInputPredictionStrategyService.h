#pragma once

#include "game_input.h"

// Interface to create the base of a prediction strategy.
struct IInputPredictionStrategyService
{
    // When GGPO can't retrieve an input, request a prediction from the strategy
    virtual void requestPrediction(int requestedFrame, char const* buffer, GameInput* input) = 0;
};
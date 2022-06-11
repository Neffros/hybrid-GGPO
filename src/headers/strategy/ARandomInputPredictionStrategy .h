#pragma once

#include "IInputPredictionStrategy.h"

//Strategy to predict a random input
class RandomInputPredictionStrategy : public IInputPredictionStrategy
{
    virtual void onFrameAdvanced(int frame, char const* buffer, GameInput* input) override {}

    virtual void requestPrediction(int requestedFrame, char const* buffer, GameInput* input) override
    {
        input->set(0);
    }
};
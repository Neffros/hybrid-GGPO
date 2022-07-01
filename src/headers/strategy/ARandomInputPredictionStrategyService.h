#pragma once

#include "IInputPredictionStrategyService.h"

//Strategy to predict a random input
class RandomInputPredictionStrategy : public IInputPredictionStrategyService
{
    virtual void requestPrediction(int requestedFrame, char const* buffer, void* values, int size) override
    {
        *values = rand();
    }
};
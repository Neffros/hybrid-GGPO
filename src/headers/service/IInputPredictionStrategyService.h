#pragma once

#include "IHybridGGPOService.h"

namespace HybridGGPO
{
    /// <summary>
    /// Service holding an input prediction strategy which can be requested in case of missing inputs
    /// </summary>
    class IInputPredictionStrategyService : public IHybridGGPOService
    {
    public:
        /// <summary>
        /// Delivers an input prediction following the strategy when GGPO cannot retrieve an input
        /// </summary>
        /// <param name="requestedFrame">Frame to predict an input for</param>
        /// <param name="values">Input values</param>
        /// <param name="size">Size of the input</param>
        virtual void    predict(int requestedFrame, int player, int size) = 0;
    };
}

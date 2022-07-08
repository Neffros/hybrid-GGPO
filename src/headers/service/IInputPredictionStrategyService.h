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
        /// Receives a confirmed input
        /// </summary>
        /// <param name="frameNumber">Frame of the played input</param>
        /// <param name="inputs">Played input values</param>
        /// <param name="inputSize">Size of the input</param>
        /// <param name="playerIndex">Player index in the session</param>
        virtual void    confirm(int frameNumber, void* inputs, int inputSize, int playerIndex) = 0;

        /// <summary>
        /// Delivers an input prediction following the strategy when GGPO cannot retrieve an input
        /// </summary>
        /// <param name="requestedFrame">Frame to predict an input for</param>
        /// <param name="inputs">Out parameter for input values</param>
        /// <param name="inputSize">Size of the input</param>
        /// <param name="playerIndex">Player index in the session</param>
        virtual void    predict(int requestedFrame, void* inputs, int inputSize, int playerIndex) = 0;
    };
}

#pragma once

#include "IHybridGGPOService.h"

namespace HybridGGPO
{
    /// <summary>
    /// Service receiving the generated game states after the game's frame advancing
    /// </summary>
    class IGameStateService : public IHybridGGPOService
    {
    public:
        /// <summary>
        /// Fired when a game state is generated with the use of confirmed inputs and received in GGPO
        /// </summary>
        /// <param name="serializedData">
        /// The serialized data of the game state, can be reinterpreted.
        /// If possible, use the game's own state data to avoid reinterpret cast
        /// </param>
        /// <param name="frameCount">Current frame count</param>
        virtual void    receiveConfirmedGameState(unsigned char* const serializedData, int frameCount) = 0;

        /// <summary>
        /// Fired when a game state is generated and received in GGPO
        /// </summary>
        /// <param name="serializedData">
        /// The serialized data of the game state, can be reinterpreted.
        /// If possible, use the game's own state data to avoid reinterpret cast
        /// </param>
        /// <param name="frameCount">Current frame count</param>
        virtual void    receiveGameState(unsigned char* const serializedData, int frameCount) = 0;
    };
}

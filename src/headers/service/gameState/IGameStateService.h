#pragma once


// The access point towards the game state saved by GGPO.
// IGameStateService is only called by a final game State, not impacted by a prediction.
class IGameStateService
{
    virtual double* ConvertGameStateToDataset(char* gameState) = 0;
};
#pragma once

#include "IGameStateService.h"
#include "strategy/IInputPredictionStrategyService.h"

//HybridGGPOServiceProvider exposes the different services of hybrid GGPO.
class HybridGGPOServiceProvider
{
private:
    IGameStateService* _gameStateService;
    IInputPredictionStrategyService* _strategyService;
public:
    HybridGGPOServiceProvider(IGameStateService* gameStateService, IInputPredictionStrategyService* strategyService);
    IGameStateService* getGameStateService();
    IInputPredictionStrategyService* getStrategyService();

};
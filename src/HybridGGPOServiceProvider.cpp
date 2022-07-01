#include "headers/service/HybridGGPOServiceProvider.h"

HybridGGPOServiceProvider::HybridGGPOServiceProvider(IGameStateService *gameStateService,
                                                     IInputPredictionStrategyService *strategyService) : _gameStateService(gameStateService), _strategyService(strategyService) {}

IGameStateService *HybridGGPOServiceProvider::getGameStateService() {
    return this->_gameStateService;
}

IInputPredictionStrategyService *HybridGGPOServiceProvider::getStrategyService() {
    return this->_strategyService;
}

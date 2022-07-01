#include "headers/HybridGGPOServiceProvider.h"

HybridGGPOServiceProvider::HybridGGPOServiceProvider(IGameStateService *gameStateService,
                                                     IInputPredictionStrategyService *strategyService) : _gameStateService(gameStateService), _strategyService(strategyService) {}
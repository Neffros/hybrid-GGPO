#include "../headers/service/HybridGGPOServiceProvider.h"

using namespace HybridGGPO;

HybridGGPOServiceProvider::HybridGGPOServiceProvider(
	IGameStateService* gameStateService,
	IInputPredictionStrategyService* inputPredictionStrategyService
) :
	_gameStateService(gameStateService),
	_inputPredictionStrategyService(inputPredictionStrategyService)
{
}

void HybridGGPOServiceProvider::init()
{
	if (this->_gameStateService != NULL)
		this->_gameStateService->init(this);
	
	if (this->_inputPredictionStrategyService != NULL)
		this->_inputPredictionStrategyService->init(this);
}

IGameStateService* HybridGGPOServiceProvider::getGameStateService() const
{
	return this->_gameStateService;
}

IInputPredictionStrategyService* HybridGGPOServiceProvider::getInputPredictionStrategyService() const
{
	return this->_inputPredictionStrategyService;
}

void HybridGGPOServiceProvider::setGameStateService(IGameStateService* service)
{
	if (this->_gameStateService != NULL)
		this->_gameStateService->eject();

	this->_gameStateService = service;

	if (this->_gameStateService != NULL)
		this->_gameStateService->init(this);
}

void HybridGGPOServiceProvider::setInputPredictionStrategyService(IInputPredictionStrategyService* service)
{
	if (this->_inputPredictionStrategyService != NULL)
		this->_inputPredictionStrategyService->eject();

	this->_inputPredictionStrategyService = service;

	if (this->_inputPredictionStrategyService != NULL)
		this->_inputPredictionStrategyService->init(this);
}

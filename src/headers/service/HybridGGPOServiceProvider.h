#pragma once

#include <memory>
#include <ggponet.h>

#include <service/IInputPredictionStrategyService.h>
#include <service/IGameStateService.h>

namespace HybridGGPO
{
	class GGPO_API HybridGGPOServiceProvider
	{
	private:
		IGameStateService*					_gameStateService;
		IInputPredictionStrategyService*	_inputPredictionStrategyService;

	public:
		/// <summary>
		/// Class constructor
		/// </summary>
		/// <param name="gameStateService">
		/// Pointer on an instance of a game state service, accessing the game state generation
		/// </param>
		/// <param name="inputPredictionStrategyService">
		/// Pointer on an instance of an input prediction strategy service, required to offer a prediction when GGPO cannot retrieve distant inputs
		/// </param>
		HybridGGPOServiceProvider(
			IGameStateService* gameStateService,
			IInputPredictionStrategyService* inputPredictionStrategyService
		);

		/// <summary>
		/// Initializes the service provider and its services
		/// </summary>
		void								init();

		/// <summary>
		/// Gets the current game state service
		/// </summary>
		/// <returns>A pointer on an game state service</returns>
		IGameStateService*					getGameStateService() const;

		/// <summary>
		/// Gets the current input prediction strategy service
		/// </summary>
		/// <returns>A pointer on an input prediction strategy service</returns>
		IInputPredictionStrategyService*	getInputPredictionStrategyService() const;

		/// <summary>
		/// Sets the current game state service
		/// </summary>
		/// <param name="service">A pointer on a game state service</param>
		void								setGameStateService(IGameStateService* service);

		/// <summary>
		/// Sets the current input prediction strategy service
		/// </summary>
		/// <param name="service">A pointer on an input prediction strategy service</param>
		void								setInputPredictionStrategyService(IInputPredictionStrategyService* service);
	};
}

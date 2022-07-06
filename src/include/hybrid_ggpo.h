#pragma once

#include <ggponet.h>

#include <service/HybridGGPOServiceProvider.h>

using namespace HybridGGPO;

/// <summary>
/// Launches a hybrid session
/// </summary>
/// <param name="session">Out paramater for the session</param>
/// <param name="cb">Callbacks for game and state management</param>
/// <param name="serviceProvider">Holds all the required services for the hybrid session</param>
/// <param name="game">Name of the game</param>
/// <param name="num_players">Number of players for this session</param>
/// <param name="input_size">Game input size</param>
/// <param name="localport">Port to bind for the UDP protocol</param>
/// <param name="useHybridSession">Indicates if we should really use hybrid session</param>
/// <returns>The success or failure code</returns>
GGPO_API GGPOErrorCode __cdecl ggpo_start_hybrid_session(
	GGPOSession** session,
	GGPOSessionCallbacks* cb,
	HybridGGPOServiceProvider* serviceProvider,
	const char* game,
	int num_players,
	int input_size,
	unsigned short localport,
	bool useHybridSession
);

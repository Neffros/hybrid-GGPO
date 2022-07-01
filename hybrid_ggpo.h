#pragma once

#include <ggponet.h>

#include "src/headers/strategy/IInputPredictionStrategyService.h"

GGPO_API GGPOErrorCode __cdecl ggpo_start_hybrid_session(
    GGPOSession** session,
    GGPOSessionCallbacks* cb,
    const char* game,
    int num_players,
    int input_size,
    unsigned short localport,
    bool useHybridSession,
    IInputPredictionStrategyService* inputPredictionStrategy
);

// TODD: add ggpo_set_prediction_strategy for session

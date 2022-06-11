#pragma once

#include "ggponet.h"

#include "strategy/IInputPredictionStrategy.h"

GGPO_API GGPOErrorCode __cdecl ggpo_start_hybrid_session(
    GGPOSession** session,
    GGPOSessionCallbacks* cb,
    const char* game,
    int num_players,
    int input_size,
    unsigned short localport,
    bool useHybridSession,
    IInputPredictionStrategy* inputPredictionStrategy
);

// TODD: add ggpo_set_prediction_strategy for session

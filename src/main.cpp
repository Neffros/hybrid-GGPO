#include "hybrid_ggpo.h"

#include "headers/session/HybridP2PSession.h"

GGPOErrorCode ggpo_start_hybrid_session(
    GGPOSession** session,
    GGPOSessionCallbacks* cb,
    const char* game,
    int num_players,
    int input_size,
    unsigned short localport,
    bool useHybridSession,
    IInputPredictionStrategyService* inputPredictionStrategy
) {
    if (!useHybridSession) {
        return ggpo_start_session(session, cb, game, num_players, input_size, localport);
    }

    *session = (GGPOSession*)new HybridGGPO::HybridP2PSession(
        cb,
        game,
        localport,
        num_players,
        input_size,
        inputPredictionStrategy
    );

    return GGPO_OK;
}

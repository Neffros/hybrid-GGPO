#include "hybrid_ggpo.h"

#include "headers/session/HybridP2PSession.h"

using namespace HybridGGPO;

GGPOErrorCode ggpo_start_hybrid_session(
    GGPOSession** session,
    GGPOSessionCallbacks* cb,
    HybridGGPOServiceProvider* serviceProvider,
    const char* game,
    int num_players,
    int input_size,
    unsigned short localport,
    bool useHybridSession
) {
    if (!useHybridSession) {
        return ggpo_start_session(session, cb, game, num_players, input_size, localport);
    }

    *session = (GGPOSession*)new HybridGGPO::HybridP2PSession(
        cb,
        serviceProvider,
        game,
        localport,
        num_players,
        input_size
    );

    return GGPO_OK;
}

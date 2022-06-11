set(HYBRID_GGPO_LIB_INC_NOFILTER
	"../ggpo/src/lib/ggpo/bitvector.h"
	"../ggpo/src/lib/ggpo/game_input.h"
	"../ggpo/src/lib/ggpo/input_queue.h"
	"../ggpo/src/lib/ggpo/log.h"
	"../ggpo/src/lib/ggpo/poll.h"
	"../ggpo/src/lib/ggpo/ring_buffer.h"
	"../ggpo/src/lib/ggpo/sync.h"
	"../ggpo/src/lib/ggpo/timesync.h"
	"../ggpo/src/lib/ggpo/types.h"
	"../ggpo/src/lib/ggpo/zconf.h"
	"../ggpo/src/lib/ggpo/zlib.h"
	"headers/synchronisation/SyncWithPredictionStrategy.h"
)

set(HYBRID_GGPO_LIB_SRC_NOFILTER
	"../ggpo/src/lib/ggpo/bitvector.cpp"
	"../ggpo/src/lib/ggpo/game_input.cpp"
	"../ggpo/src/lib/ggpo/input_queue.cpp"
	"../ggpo/src/lib/ggpo/log.cpp"
	"../ggpo/src/lib/ggpo/main.cpp"
	"../ggpo/src/lib/ggpo/poll.cpp"
	"../ggpo/src/lib/ggpo/sync.cpp"
	"../ggpo/src/lib/ggpo/timesync.cpp"
	"synchronisation/SyncWithPredictionStrategy.cpp"
	"main.cpp"
)

if(UNIX)
	set(HYBRID_GGPO_LIB_SRC_NOFILTER
		${HYBRID_GGPO_LIB_SRC_NOFILTER}
		"../ggpo/src/lib/ggpo/platform_linux.cpp"
	)
endif()

if(WIN32)
	set(HYBRID_GGPO_LIB_SRC_NOFILTER
		${HYBRID_GGPO_LIB_SRC_NOFILTER}
		"../ggpo/src/lib/ggpo/platform_windows.cpp"
	)
endif()

set(HYBRID_GGPO_LIB_INC_NETWORK
	"../ggpo/src/lib/ggpo/network/udp.h"
	"../ggpo/src/lib/ggpo/network/udp_msg.h"
	"../ggpo/src/lib/ggpo/network/udp_proto.h"
)

set(HYBRID_GGPO_LIB_SRC_NETWORK
	"../ggpo/src/lib/ggpo/network/udp.cpp"
	"../ggpo/src/lib/ggpo/network/udp_proto.cpp"
)

set(HYBRID_GGPO_LIB_INC_BACKENDS
	"../ggpo/src/lib/ggpo/backends/backend.h"
	"../ggpo/src/lib/ggpo/backends/p2p.h"
	"../ggpo/src/lib/ggpo/backends/spectator.h"
	"../ggpo/src/lib/ggpo/backends/synctest.h"
	"headers/session/HybridP2PSession.h"
)

set(HYBRID_GGPO_LIB_SRC_BACKENDS
	"../ggpo/src/lib/ggpo/backends/p2p.cpp"
	"../ggpo/src/lib/ggpo/backends/spectator.cpp"
	"../ggpo/src/lib/ggpo/backends/synctest.cpp"
	"session/HybridP2PSession.cpp"
)

set(HYBRID_GGPO_PUBLIC_INC
	"../ggpo/src/include/ggponet.h"
	"include/hybridggpo.h"
)

source_group(" " FILES ${HYBRID_GGPO_LIB_INC_NOFILTER} ${HYBRID_GGPO_LIB_SRC_NOFILTER})
source_group("Network" FILES ${HYBRID_GGPO_LIB_INC_NETWORK} ${HYBRID_GGPO_LIB_SRC_NETWORK})
source_group("Backends" FILES ${HYBRID_GGPO_LIB_INC_BACKENDS} ${HYBRID_GGPO_LIB_SRC_BACKENDS})
source_group("Public" FILES ${HYBRID_GGPO_PUBLIC_INC})

set(HYBRID_GGPO_LIB_SRC
	${HYBRID_GGPO_LIB_INC_NOFILTER}
	${HYBRID_GGPO_LIB_SRC_NOFILTER}
	${HYBRID_GGPO_LIB_INC_NETWORK}
	${HYBRID_GGPO_LIB_SRC_NETWORK}
	${HYBRID_GGPO_LIB_INC_BACKENDS}
	${HYBRID_GGPO_LIB_SRC_BACKENDS}
	${HYBRID_GGPO_PUBLIC_INC}
)
#pragma once

#include "types.h"
#include "ggponet.h"
#include "game_input.h"
#include "input_queue.h"
#include "ring_buffer.h"
#include "network/udp_msg.h"
#include "HybridInputQueue.h"

#include "../service/strategy/IInputPredictionStrategyService.h"

#define MAX_HYBRID_PREDICTION_FRAMES    20

class SyncTestBackend;

namespace HybridGGPO
{
    /// <summary>
    /// HybridGGPO authors' note:
    /// Literally the Sync class from GGPO using prediction strategy when a player's input queue is predicting
    /// </summary>
	class HybridSync {
	public:
		struct Config {
			GGPOSessionCallbacks    callbacks;
			int                     num_prediction_frames;
			int                     num_players;
			int                     input_size;
		};
		struct Event {
			enum {
				ConfirmedInput,
			} type;
			union {
				struct {
					GameInput   input;
				} confirmedInput;
			} u;
		};

	public:
		HybridSync(UdpMsg::connect_status* connect_status);
		virtual ~HybridSync();

		void Init(Config& config, IInputPredictionStrategyService* inputPredictionStrategy);

		void SetLastConfirmedFrame(int frame);
		void SetFrameDelay(int queue, int delay);
		bool AddLocalInput(int queue, GameInput& input);
		void AddRemoteInput(int queue, GameInput& input);
		int GetConfirmedInputs(void* values, int size, int frame);
		int SynchronizeInputs(void* values, int size);

		void CheckSimulation(int timeout);
		void AdjustSimulation(int seek_to);
		void IncrementFrame(void);

		int GetFrameCount() { return _framecount; }
		bool InRollback() { return _rollingback; }

		bool GetEvent(Event& e);

	protected:
		friend SyncTestBackend;

		struct SavedFrame {
			byte* buf;
			int      cbuf;
			int      frame;
			int      checksum;
			SavedFrame() : buf(NULL), cbuf(0), frame(-1), checksum(0) { }
		};
		struct SavedState {
			SavedFrame frames[MAX_HYBRID_PREDICTION_FRAMES + 2];
			int head;
		};

		void LoadFrame(int frame);
		void SaveCurrentFrame();
		int FindSavedFrameIndex(int frame);
		SavedFrame& GetLastSavedFrame();

		bool CreateQueues(Config& config);
		bool CheckSimulationConsistency(int* seekTo);
		void ResetPrediction(int frameNumber);

	protected:
		GGPOSessionCallbacks _callbacks;
		SavedState     _savedstate;
		Config         _config;

		bool           _rollingback;
		int            _last_confirmed_frame;
		int            _framecount;
		int            _max_prediction_frames;

        HybridInputQueue*					_input_queues;
		IInputPredictionStrategyService*	_inputPredictionStrategy;

		RingBuffer<Event, 32> _event_queue;
		UdpMsg::connect_status* _local_connect_status;
	};
}

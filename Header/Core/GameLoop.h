#include "../Event/Event.h"
#include "GameWindowManager.h"
#include "../Gameplay/Gameplay.h"

namespace Core_N
{
	class GameLoop
	{
		private:
			GameWindowManager *game_window_manager;
			Event_N::EventManager *event_manager;
			Gameplay_N::GameplayManager *gameplay_manager;

		public:
			void initialize();
			bool isGameRunning();
			void poolEvent();
			void update();
			void render();
	};
}
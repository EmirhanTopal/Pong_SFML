#include "Event.h"
#include "GameWindowManager.h"

namespace Core_N
{
	class GameLoop
	{
		private:
			GameWindowManager *game_window_manager;
			Event_N::EventManager *event_manager;
		public:
			void initialize();
			bool isGameRunning();
			void poolEvent(RenderWindow *_game_window);
			void update();
			void render();
	};
}
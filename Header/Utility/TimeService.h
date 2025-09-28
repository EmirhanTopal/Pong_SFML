#pragma once
#include <chrono>

namespace Utility_N
{
	class TimeService
	{
		private:
			std::chrono::steady_clock::time_point previous_time;
			float delta_time;
			float delay_duration;

			float calculateDeltaTime();
			void updatePreviousTime();
			void updateDeltaTime();

		public:
			float elapsed_delay_time;

			void initialize();
			void update();
			float getDeltaTime();
			bool updateDelayTime(float _delta_time);

	};
}
#include "../../Header/Utility/TimeService.h"

namespace Utility_N
{
	float TimeService::calculateDeltaTime()
	{
		std::chrono::steady_clock::time_point current_time;
		current_time = std::chrono::steady_clock::now();
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(current_time - previous_time).count();

		return static_cast<float>(delta) / 1000000.0f;
	}

	void TimeService::updatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}

	void TimeService::updateDeltaTime()
	{
		delta_time = calculateDeltaTime();
		updatePreviousTime();
	}

	void TimeService::initialize()
	{
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;
		delay_duration = 2;
	}

	void TimeService::update()
	{
		updateDeltaTime();
	}

	float TimeService::getDeltaTime()
	{
		return delta_time;
	}

	bool TimeService::updateDelayTime(float _delta_time)
	{
		elapsed_delay_time += _delta_time;

		if (elapsed_delay_time >= delay_duration)
			return true;
		return false;
	}
}
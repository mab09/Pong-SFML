#pragma once
#include <chrono>

namespace Utility
{
	class TimeService {
	private:
		std::chrono::steady_clock::time_point previous_time;
		float delta_time;

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime(); // Update previous_time to the current time

	public:
		void initialize();
		void update();
		float getDeltaTime();
	};
}
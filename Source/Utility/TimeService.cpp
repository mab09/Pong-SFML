#include "../../Header/Utility/TimeService.h"

namespace Utility
{
    void TimeService::initialize() {
        previous_time = std::chrono::steady_clock::now();
        delta_time = 0;
    }

    float TimeService::calculateDeltaTime() {
        // Get time difference in microseconds
        int delta = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();

        // Convert to seconds
        return static_cast<float>(delta) / 1000000.0f;
    }

    void TimeService::updateDeltaTime() {
        delta_time = calculateDeltaTime();
        updatePreviousTime();
    }

    void TimeService::updatePreviousTime() {
        previous_time = std::chrono::steady_clock::now();
    }

    void TimeService::update() {
        updateDeltaTime();
    }

    float TimeService::getDeltaTime() {
        return delta_time;
    }
}
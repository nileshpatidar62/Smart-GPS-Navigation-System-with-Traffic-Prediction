#include "TrafficPredictor.h"

TrafficPredictor::TrafficPredictor() {
}

double TrafficPredictor::predictTrafficMultiplier(
    int hour,
    int dayOfWeek,
    double distance
) const {

    double multiplier = 1.0;

    // ---------------------------------
    // Feature 1: Time of Day
    // ---------------------------------

    // Morning rush hour
    if (hour >= 7 && hour <= 10) {
        multiplier += 0.55;
    }

    // Evening rush hour
    else if (hour >= 17 && hour <= 20) {
        multiplier += 0.70;
    }

    // Moderate afternoon traffic
    else if (hour >= 12 && hour <= 16) {
        multiplier += 0.25;
    }

    // Late night - low traffic
    else if (hour >= 22 || hour <= 5) {
        multiplier -= 0.15;
    }

    // ---------------------------------
    // Feature 2: Day of Week
    // 1 = Monday
    // 7 = Sunday
    // ---------------------------------

    if (dayOfWeek >= 1 && dayOfWeek <= 5) {
        multiplier += 0.15;
    }
    else {
        multiplier -= 0.05;
    }

    // ---------------------------------
    // Feature 3: Road Distance
    // Longer routes have slightly
    // higher congestion probability.
    // ---------------------------------

    if (distance > 20) {
        multiplier += 0.10;
    }

    if (distance > 40) {
        multiplier += 0.10;
    }

    // Prevent unrealistic values
    multiplier = max(0.70, multiplier);

    return multiplier;
}

double TrafficPredictor::predictTravelTime(
    double baseTime,
    int hour,
    int dayOfWeek,
    double distance
) const {

    double multiplier =
        predictTrafficMultiplier(
            hour,
            dayOfWeek,
            distance
        );

    return baseTime * multiplier;
}

TrafficPredictor::TrafficLevel
TrafficPredictor::getTrafficLevel(double multiplier) const {

    if (multiplier < 1.10) {
        return LOW;
    }

    if (multiplier < 1.40) {
        return MODERATE;
    }

    if (multiplier < 1.75) {
        return HIGH;
    }

    return SEVERE;
}

string TrafficPredictor::trafficLevelToString(
    TrafficLevel level
) const {

    switch (level) {

        case LOW:
            return "Low";

        case MODERATE:
            return "Moderate";

        case HIGH:
            return "High";

        case SEVERE:
            return "Severe";
    }

    return "Unknown";
}

double TrafficPredictor::getCongestionPercentage(
    double multiplier
) const {

    if (multiplier <= 1.0) {
        return 0.0;
    }

    return (multiplier - 1.0) * 100.0;
}

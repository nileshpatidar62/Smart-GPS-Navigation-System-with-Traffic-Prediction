#ifndef TRAFFICPREDICTOR_H
#define TRAFFICPREDICTOR_H

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class TrafficPredictor {

public:

    enum TrafficLevel {
        LOW,
        MODERATE,
        HIGH,
        SEVERE
    };

    TrafficPredictor();

    double predictTrafficMultiplier(
        int hour,
        int dayOfWeek,
        double distance
    ) const;

    double predictTravelTime(
        double baseTime,
        int hour,
        int dayOfWeek,
        double distance
    ) const;

    TrafficLevel getTrafficLevel(double multiplier) const;

    string trafficLevelToString(TrafficLevel level) const;

    double getCongestionPercentage(double multiplier) const;
};

#endif

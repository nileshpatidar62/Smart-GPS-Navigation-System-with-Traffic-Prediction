 #ifndef GPS_H
#define GPS_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>

#include "Graph.h"
#include "TrafficPredictor.h"

using namespace std;

struct RouteResult {

    vector<int> path;

    double totalDistance;
    double totalTime;

    bool found;

    RouteResult() {
        totalDistance = 0;
        totalTime = 0;
        found = false;
    }
};

class GPS {

private:

    Graph& graph;

    TrafficPredictor trafficPredictor;

public:

    GPS(Graph& g);

    RouteResult findShortestRoute(
        const string& source,
        const string& destination
    );

    RouteResult findFastestRoute(
        const string& source,
        const string& destination,
        int hour,
        int dayOfWeek
    );

    void displayRoute(
        const RouteResult& result,
        int hour,
        int dayOfWeek
    );

    void compareRoutes(
        const string& source,
        const string& destination,
        int hour,
        int dayOfWeek
    );
};

#endif

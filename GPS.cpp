#include "GPS.h"

GPS::GPS(Graph& g) : graph(g) {
}


// =====================================================
// SHORTEST ROUTE BASED ON DISTANCE
// =====================================================

RouteResult GPS::findShortestRoute(
    const string& source,
    const string& destination
) {

    RouteResult result;

    int sourceId = graph.getCityId(source);
    int destinationId = graph.getCityId(destination);

    if (sourceId == -1 || destinationId == -1) {
        return result;
    }

    int n = graph.getNumberOfCities();

    vector<double> distance(
        n,
        numeric_limits<double>::infinity()
    );

    vector<int> parent(n, -1);

    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;

    distance[sourceId] = 0;

    pq.push({0, sourceId});


    while (!pq.empty()) {

        double currentDistance = pq.top().first;

        int currentNode = pq.top().second;

        pq.pop();


        if (currentDistance > distance[currentNode]) {
            continue;
        }


        if (currentNode == destinationId) {
            break;
        }


        for (const Edge& edge :
             graph.getNeighbors(currentNode)) {

            double newDistance =
                currentDistance + edge.distance;


            if (newDistance <
                distance[edge.destination]) {

                distance[edge.destination] =
                    newDistance;

                parent[edge.destination] =
                    currentNode;

                pq.push({
                    newDistance,
                    edge.destination
                });
            }
        }
    }


    if (distance[destinationId] ==
        numeric_limits<double>::infinity()) {

        return result;
    }


    vector<int> path;

    int current = destinationId;


    while (current != -1) {

        path.push_back(current);

        current = parent[current];
    }


    reverse(
        path.begin(),
        path.end()
    );


    result.path = path;

    result.totalDistance =
        distance[destinationId];

    result.totalTime = 0;

    result.found = true;


    // Calculate base travel time

    for (int i = 0;
         i < static_cast<int>(path.size()) - 1;
         i++) {

        int u = path[i];

        int v = path[i + 1];


        for (const Edge& edge :
             graph.getNeighbors(u)) {

            if (edge.destination == v) {

                result.totalTime +=
                    edge.baseTime;

                break;
            }
        }
    }


    return result;
}


// =====================================================
// AI TRAFFIC AWARE FASTEST ROUTE
// =====================================================

RouteResult GPS::findFastestRoute(
    const string& source,
    const string& destination,
    int hour,
    int dayOfWeek
) {

    RouteResult result;

    int sourceId =
        graph.getCityId(source);

    int destinationId =
        graph.getCityId(destination);


    if (sourceId == -1 ||
        destinationId == -1) {

        return result;
    }


    int n =
        graph.getNumberOfCities();


    vector<double> travelTime(
        n,
        numeric_limits<double>::infinity()
    );

    vector<int> parent(
        n,
        -1
    );


    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;


    travelTime[sourceId] = 0;


    pq.push({
        0,
        sourceId
    });


    while (!pq.empty()) {

        double currentTime =
            pq.top().first;

        int currentNode =
            pq.top().second;

        pq.pop();


        if (currentTime >
            travelTime[currentNode]) {

            continue;
        }


        if (currentNode ==
            destinationId) {

            break;
        }


        for (const Edge& edge :
             graph.getNeighbors(currentNode)) {


            double predictedTime =
                trafficPredictor.predictTravelTime(
                    edge.baseTime,
                    hour,
                    dayOfWeek,
                    edge.distance
                );


            double newTime =
                currentTime +
                predictedTime;


            if (newTime <
                travelTime[edge.destination]) {


                travelTime[edge.destination] =
                    newTime;


                parent[edge.destination] =
                    currentNode;


                pq.push({
                    newTime,
                    edge.destination
                });
            }
        }
    }


    if (travelTime[destinationId] ==
        numeric_limits<double>::infinity()) {

        return result;
    }


    vector<int> path;


    int current =
        destinationId;


    while (current != -1) {

        path.push_back(
            current
        );

        current =
            parent[current];
    }


    reverse(
        path.begin(),
        path.end()
    );


    double totalDistance = 0;


    for (int i = 0;
         i < static_cast<int>(path.size()) - 1;
         i++) {


        int u =
            path[i];

        int v =
            path[i + 1];


        for (const Edge& edge :
             graph.getNeighbors(u)) {


            if (edge.destination == v) {

                totalDistance +=
                    edge.distance;

                break;
            }
        }
    }


    result.path =
        path;


    result.totalDistance =
        totalDistance;


    result.totalTime =
        travelTime[destinationId];


    result.found =
        true;


    return result;
}


// =====================================================
// DISPLAY ROUTE
// =====================================================

void GPS::displayRoute(
    const RouteResult& result,
    int hour,
    int dayOfWeek
) {

    if (!result.found) {

        cout << "\nRoute not found.\n";

        return;
    }


    cout << "\n========================================\n";

    cout << "             ROUTE RESULT\n";

    cout << "========================================\n";


    cout << "\nRecommended Route:\n\n";


    for (int i = 0;
         i < static_cast<int>(result.path.size());
         i++) {


        cout <<
            graph.getCityName(
                result.path[i]
            );


        if (i !=
            static_cast<int>(result.path.size()) - 1) {

            cout << " -> ";
        }
    }


    cout << "\n\nTotal Distance : "
         << fixed
         << setprecision(2)
         << result.totalDistance
         << " km";


    cout << "\nEstimated Time : "
         << result.totalTime
         << " minutes";


    double multiplier =
        trafficPredictor.predictTrafficMultiplier(
            hour,
            dayOfWeek,
            result.totalDistance
        );


    TrafficPredictor::TrafficLevel level =
        trafficPredictor.getTrafficLevel(
            multiplier
        );


    cout << "\nTraffic Level  : "
         << trafficPredictor
                .trafficLevelToString(level);


    cout << "\nCongestion     : "
         << trafficPredictor
                .getCongestionPercentage(multiplier)
         << "%";


    cout << "\n========================================\n";
}


// =====================================================
// COMPARE DISTANCE VS AI ROUTE
// =====================================================

void GPS::compareRoutes(
    const string& source,
    const string& destination,
    int hour,
    int dayOfWeek
) {

    RouteResult shortest =
        findShortestRoute(
            source,
            destination
        );


    RouteResult fastest =
        findFastestRoute(
            source,
            destination,
            hour,
            dayOfWeek
        );


    cout << "\n\n========================================\n";

    cout << "          ROUTE COMPARISON\n";

    cout << "========================================\n";


    if (shortest.found) {

        cout << "\nShortest Distance Route:\n";

        for (int i = 0;
             i < static_cast<int>(shortest.path.size());
             i++) {


            cout <<
                graph.getCityName(
                    shortest.path[i]
                );


            if (i !=
                static_cast<int>(shortest.path.size()) - 1) {

                cout << " -> ";
            }
        }


        cout << "\nDistance: "
             << shortest.totalDistance
             << " km\n";
    }


    if (fastest.found) {

        cout << "\nAI Traffic Optimized Route:\n";


        for (int i = 0;
             i < static_cast<int>(fastest.path.size());
             i++) {


            cout <<
                graph.getCityName(
                    fastest.path[i]
                );


            if (i !=
                static_cast<int>(fastest.path.size()) - 1) {

                cout << " -> ";
            }
        }


        cout << "\nDistance: "
             << fastest.totalDistance
             << " km";


        cout << "\nPredicted Time: "
             << fastest.totalTime
             << " minutes\n";
    }


    cout << "\n========================================\n";
}

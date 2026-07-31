#ifndef GPS_H
#define GPS_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <limits>

#include "Graph.h"

using namespace std;

class GPS
{
private:

    Graph &graph;

    // Calculate heuristic for A* Search
    int heuristic(const string &current,
                  const string &destination);

    // Print shortest path
    void printPath(
        unordered_map<string, string> &parent,
        const string &source,
        const string &destination);

public:

    // Constructor
    GPS(Graph &g);

    // Dijkstra Algorithm
    void shortestRoute(
        const string &source,
        const string &destination);

    // A* Search Algorithm
    void fastestRoute(
        const string &source,
        const string &destination);

    // Calculate total distance of a path
    int calculateDistance(
        const vector<string> &path);

    // Check if city exists
    bool isValidCity(
        const string &city);

    // Display available cities
    void displayCities();

    // Print complete route
    void displayRoute(
        const vector<string> &path);

    // Show route statistics
    void routeStatistics(
        const vector<string> &path);

    // Find alternative route
    void alternativeRoute(
        const string &source,
        const string &destination);
};

#endif

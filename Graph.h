 

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

//--------------------------------------------
// Edge Structure
//--------------------------------------------
struct Edge
{
    string destination;
    double distance;      // in KM
    int trafficLevel;     // 1=Low 2=Medium 3=High
    double delay;         // Delay in minutes

    Edge(string dest, double dist, int traffic = 1, double d = 0.0)
    {
        destination = dest;
        distance = dist;
        trafficLevel = traffic;
        delay = d;
    }
};

//--------------------------------------------
// Graph Class
//--------------------------------------------
class Graph
{
private:

    unordered_map<string, vector<Edge>> adjacencyList;

public:

    Graph();

    //-------------------------
    // City Operations
    //-------------------------
    void addCity(const string &city);

    bool cityExists(const string &city) const;

    vector<string> getCities() const;

    //-------------------------
    // Road Operations
    //-------------------------
    void addRoad(const string &source,
                 const string &destination,
                 double distance);

    void removeRoad(const string &source,
                    const string &destination);

    //-------------------------
    // Display
    //-------------------------
    void displayGraph() const;

    //-------------------------
    // Traffic
    //-------------------------
    void updateTraffic();

    double getTrafficDelay(int trafficLevel) const;

    //-------------------------
    // Shortest Path
    //-------------------------
    pair<double, vector<string>>
    dijkstra(const string &source,
             const string &destination);

    //-------------------------
    // Route Information
    //-------------------------
    double calculateRouteDistance(
            const vector<string> &path);

    double calculateTravelTime(
            const vector<string> &path);

    //-------------------------
    // Utilities
    //-------------------------
    bool empty() const;

    void clear();

    unordered_map<string, vector<Edge>>& getGraph();
};

#endif

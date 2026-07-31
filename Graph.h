#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Edge {
    int destination;
    double distance;
    double baseTime;

    Edge(int dest, double dist, double time)
        : destination(dest), distance(dist), baseTime(time) {}
};

class Graph {
private:
    unordered_map<string, int> cityToId;
    vector<string> idToCity;
    vector<vector<Edge>> adjacencyList;

public:
    Graph();

    int addCity(const string& cityName);

    void addRoad(
        const string& source,
        const string& destination,
        double distance,
        double baseTime
    );

    int getCityId(const string& cityName) const;

    string getCityName(int id) const;

    const vector<Edge>& getNeighbors(int cityId) const;

    int getNumberOfCities() const;

    bool cityExists(const string& cityName) const;

    void displayCities() const;

    void displayGraph() const;
};

#endif

    unordered_map<string, vector<Edge>>& getGraph();
};

#endif

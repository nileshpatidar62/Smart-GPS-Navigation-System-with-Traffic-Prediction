#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Represents a road between two cities
struct Edge
{
    string destination;
    int distance;

    Edge(string dest, int dist)
    {
        destination = dest;
        distance = dist;
    }
};

class Graph
{
private:

    // Adjacency List
    unordered_map<string, vector<Edge>> adjList;

public:

    Graph();

    // Add a new city
    void addCity(const string &city);

    // Add road between two cities
    void addRoad(const string &source,
                 const string &destination,
                 int distance);

    // Check if city exists
    bool cityExists(const string &city) const;

    // Display complete graph
    void displayGraph() const;

    // Return adjacency list
    const unordered_map<string, vector<Edge>>& getGraph() const;

    // Return neighbors of a city
    const vector<Edge>& getNeighbors(const string &city) const;

    // Load road network from file
    bool loadFromFile(const string &filename);

    // Save graph to file
    bool saveToFile(const string &filename) const;

    // Total number of cities
    int totalCities() const;

    // Total number of roads
    int totalRoads() const;

    // Remove city
    void removeCity(const string &city);

    // Remove road
    void removeRoad(const string &source,
                    const string &destination);

    // Clear graph
    void clear();
};

#endif

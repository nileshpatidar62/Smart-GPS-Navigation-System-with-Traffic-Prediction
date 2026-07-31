#include "Graph.h"

#include <fstream>
#include <algorithm>

using namespace std;

// Constructor
Graph::Graph()
{
}

// Add a city
void Graph::addCity(const string &city)
{
    if (!cityExists(city))
    {
        adjList[city] = vector<Edge>();
    }
}

// Check if city exists
bool Graph::cityExists(const string &city) const
{
    return adjList.find(city) != adjList.end();
}

// Add road (Undirected Graph)
void Graph::addRoad(const string &source,
                    const string &destination,
                    int distance)
{
    if (!cityExists(source))
        addCity(source);

    if (!cityExists(destination))
        addCity(destination);

    adjList[source].push_back(Edge(destination, distance));
    adjList[destination].push_back(Edge(source, distance));
}

// Display Graph
void Graph::displayGraph() const
{
    cout << "\n========== ROAD NETWORK ==========\n";

    for (const auto &city : adjList)
    {
        cout << city.first << " -> ";

        for (const auto &road : city.second)
        {
            cout << "("
                 << road.destination
                 << ", "
                 << road.distance
                 << " km) ";
        }

        cout << endl;
    }
}

// Return adjacency list
const unordered_map<string, vector<Edge>>& Graph::getGraph() const
{
    return adjList;
}

// Return neighbors
const vector<Edge>& Graph::getNeighbors(const string &city) const
{
    return adjList.at(city);
}

// Load graph from file
bool Graph::loadFromFile(const string &filename)
{
    ifstream fin(filename);

    if (!fin.is_open())
        return false;

    clear();

    string source, destination;
    int distance;

    while (fin >> source >> destination >> distance)
    {
        addRoad(source, destination, distance);
    }

    fin.close();

    return true;
}

// Save graph to file
bool Graph::saveToFile(const string &filename) const
{
    ofstream fout(filename);

    if (!fout.is_open())
        return false;

    for (const auto &city : adjList)
    {
        for (const auto &road : city.second)
        {
            if (city.first < road.destination)
            {
                fout << city.first << " "
                     << road.destination << " "
                     << road.distance << endl;
            }
        }
    }

    fout.close();

    return true;
}

// Total cities
int Graph::totalCities() const
{
    return adjList.size();
}

// Total roads
int Graph::totalRoads() const
{
    int roads = 0;

    for (const auto &city : adjList)
        roads += city.second.size();

    return roads / 2;
}

// Remove Road
void Graph::removeRoad(const string &source,
                       const string &destination)
{
    if (!cityExists(source) || !cityExists(destination))
        return;

    auto &list1 = adjList[source];

    list1.erase(
        remove_if(list1.begin(),
                  list1.end(),
                  [&](Edge e)
                  {
                      return e.destination == destination;
                  }),
        list1.end());

    auto &list2 = adjList[destination];

    list2.erase(
        remove_if(list2.begin(),
                  list2.end(),
                  [&](Edge e)
                  {
                      return e.destination == source;
                  }),
        list2.end());
}

// Remove City
void Graph::removeCity(const string &city)
{
    if (!cityExists(city))
        return;

    for (auto &node : adjList)
    {
        auto &roads = node.second;

        roads.erase(
            remove_if(roads.begin(),
                      roads.end(),
                      [&](Edge e)
                      {
                          return e.destination == city;
                      }),
            roads.end());
    }

    adjList.erase(city);
}

// Clear graph
void Graph::clear()
{
    adjList.clear();
}

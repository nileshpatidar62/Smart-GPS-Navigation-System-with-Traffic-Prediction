#include "Graph.h"

Graph::Graph() {
}

int Graph::addCity(const string& cityName) {

    if (cityToId.find(cityName) != cityToId.end()) {
        return cityToId[cityName];
    }

    int newId = idToCity.size();

    cityToId[cityName] = newId;
    idToCity.push_back(cityName);

    adjacencyList.push_back(vector<Edge>());

    return newId;
}

void Graph::addRoad(
    const string& source,
    const string& destination,
    double distance,
    double baseTime
) {

    int sourceId = addCity(source);
    int destinationId = addCity(destination);

    // Bidirectional road
    adjacencyList[sourceId].push_back(
        Edge(destinationId, distance, baseTime)
    );

    adjacencyList[destinationId].push_back(
        Edge(sourceId, distance, baseTime)
    );
}

int Graph::getCityId(const string& cityName) const {

    auto it = cityToId.find(cityName);

    if (it == cityToId.end()) {
        return -1;
    }

    return it->second;
}

string Graph::getCityName(int id) const {

    if (id < 0 || id >= static_cast<int>(idToCity.size())) {
        return "Unknown";
    }

    return idToCity[id];
}

const vector<Edge>& Graph::getNeighbors(int cityId) const {

    return adjacencyList[cityId];
}

int Graph::getNumberOfCities() const {

    return idToCity.size();
}

bool Graph::cityExists(const string& cityName) const {

    return cityToId.find(cityName) != cityToId.end();
}

void Graph::displayCities() const {

    cout << "\nAvailable Locations:\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < static_cast<int>(idToCity.size()); i++) {
        cout << i + 1 << ". " << idToCity[i] << endl;
    }

    cout << "-----------------------------\n";
}

void Graph::displayGraph() const {

    cout << "\nRoad Network:\n";
    cout << "====================================\n";

    for (int i = 0; i < static_cast<int>(adjacencyList.size()); i++) {

        cout << idToCity[i] << " -> ";

        for (const Edge& edge : adjacencyList[i]) {

            cout << idToCity[edge.destination]
                 << " (" << edge.distance << " km)  ";
        }

        cout << endl;
    }

    cout << "====================================\n";
}

#include <iostream>
#include "Graph.h"
#include "GPS.h"
#include "TrafficPredictor.h"

using namespace std;

void menu()
{
    cout << "\n=============================================\n";
    cout << " SMART GPS ROUTE PLANNER\n";
    cout << "=============================================\n";
    cout << "1. Add City\n";
    cout << "2. Add Road\n";
    cout << "3. Display Map\n";
    cout << "4. Find Shortest Route (Dijkstra)\n";
    cout << "5. Find Fastest Route (A*)\n";
    cout << "6. Predict Traffic\n";
    cout << "7. Load Roads From File\n";
    cout << "8. Exit\n";
    cout << "=============================================\n";
    cout << "Enter Choice : ";
}

int main()
{
    Graph graph;
    GPS gps(graph);
    TrafficPredictor predictor;

    int choice;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string city;

            cout << "\nEnter City Name : ";
            cin >> city;

            graph.addCity(city);

            cout << "City Added Successfully.\n";

            break;
        }

        case 2:
        {
            string city1, city2;
            int distance;

            cout << "\nEnter Source City : ";
            cin >> city1;

            cout << "Enter Destination City : ";
            cin >> city2;

            cout << "Enter Distance (KM) : ";
            cin >> distance;

            graph.addRoad(city1, city2, distance);

            cout << "Road Added Successfully.\n";

            break;
        }

        case 3:
        {
            graph.displayGraph();
            break;
        }

        case 4:
        {
            string source, destination;

            cout << "\nEnter Source City : ";
            cin >> source;

            cout << "Enter Destination City : ";
            cin >> destination;

            gps.shortestRoute(source, destination);

            break;
        }

        case 5:
        {
            string source, destination;

            cout << "\nEnter Source City : ";
            cin >> source;

            cout << "Enter Destination City : ";
            cin >> destination;

            gps.fastestRoute(source, destination);

            break;
        }

        case 6:
        {
            predictor.predictTraffic(graph);
            break;
        }

        case 7:
        {
            string filename;

            cout << "\nEnter File Name : ";
            cin >> filename;

            graph.loadFromFile(filename);

            cout << "Road Network Loaded Successfully.\n";

            break;
        }

        case 8:
        {
            cout << "\nThank You For Using Smart GPS.\n";
            return 0;
        }

        default:
            cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}

 #include <iostream>
#include <string>
#include <limits>

#include "Graph.h"
#include "GPS.h"

using namespace std;

void createRoadNetwork(Graph &graph)
{
    int roads;

    cout << "=============================================\n";
    cout << " SMART GPS ROUTE PLANNER\n";
    cout << "=============================================\n\n";

    cout << "Enter Number of Roads : ";
    cin >> roads;

    cin.ignore();

    cout << "\nEnter Road Details\n";
    cout << "Format:\n";
    cout << "Source Destination Distance(km) BaseTime(min)\n\n";

    for (int i = 1; i <= roads; i++)
    {
        string source, destination;
        double distance, time;

        cout << "Road " << i << endl;

        cout << "Source : ";
        getline(cin, source);

        cout << "Destination : ";
        getline(cin, destination);

        cout << "Distance (km) : ";
        cin >> distance;

        cout << "Base Travel Time (minutes) : ";
        cin >> time;

        cin.ignore();

        graph.addRoad(source, destination, distance, time);

        cout << endl;
    }
}

void menu()
{
    cout << "\n=========================================\n";
    cout << "1. Display Cities\n";
    cout << "2. Display Road Network\n";
    cout << "3. Find Shortest Route\n";
    cout << "4. Find Fastest Route (AI Traffic)\n";
    cout << "5. Compare Routes\n";
    cout << "6. Exit\n";
    cout << "=========================================\n";

    cout << "Enter Choice : ";
}

int main()
{
    Graph graph;

    createRoadNetwork(graph);

    GPS gps(graph);

    int choice;

    while (true)
    {
        menu();

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            graph.displayCities();
        }

        else if (choice == 2)
        {
            graph.displayGraph();
        }

        else if (choice == 3)
        {
            string source, destination;

            cout << "\nEnter Source : ";
            getline(cin, source);

            cout << "Enter Destination : ";
            getline(cin, destination);

            RouteResult result =
                gps.findShortestRoute(source, destination);

            gps.displayRoute(result, 12, 2);
        }

        else if (choice == 4)
        {
            string source, destination;
            int hour, day;

            cout << "\nEnter Source : ";
            getline(cin, source);

            cout << "Enter Destination : ";
            getline(cin, destination);

            cout << "Current Hour (0-23): ";
            cin >> hour;

            cout << "Day (1=Mon ... 7=Sun): ";
            cin >> day;

            cin.ignore();

            RouteResult result =
                gps.findFastestRoute(
                    source,
                    destination,
                    hour,
                    day);

            gps.displayRoute(result, hour, day);
        }

        else if (choice == 5)
        {
            string source, destination;
            int hour, day;

            cout << "\nEnter Source : ";
            getline(cin, source);

            cout << "Enter Destination : ";
            getline(cin, destination);

            cout << "Current Hour (0-23): ";
            cin >> hour;

            cout << "Day (1=Mon ... 7=Sun): ";
            cin >> day;

            cin.ignore();

            gps.compareRoutes(
                source,
                destination,
                hour,
                day);
        }

        else if (choice == 6)
        {
            cout << "\nThank You for Using Smart GPS Route Planner.\n";
            break;
        }

        else
        {
            cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}

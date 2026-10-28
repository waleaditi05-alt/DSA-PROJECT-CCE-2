#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 50
#define INF 999999

class RoadNetwork
{
    string name[MAX];
    int isHospital[MAX];
    int road[MAX][MAX];
    int total;

public:
    RoadNetwork()
    {
        total = 0;
        for (int i = 0; i < MAX; i++)
        {
            isHospital[i] = 0;
            for (int j = 0; j < MAX; j++)
                road[i][j] = (i == j) ? 0 : INF;
        }
    }

    void addLocation()
    {
        if (total >= MAX)
        {
            cout << "Location limit reached!\n";
            return;
        }

        int type;
        cin.ignore(1000, '\n');
        cout << "Enter junction/hospital name: ";
        getline(cin, name[total]);

        if (name[total].empty())
        {
            cout << "Name cannot be empty!\n";
            return;
        }

        cout << "1. Road Junction\n2. Hospital\n";
        cout << "Select location type: ";
        cin >> type;

        if (type != 1 && type != 2)
        {
            cout << "Invalid type. Location not added.\n";
            return;
        }

        isHospital[total] = (type == 2);
        cout << "Location added. ID = " << total;
        if (isHospital[total])
            cout << " (Hospital)";
        else
            cout << " (Road Junction)";
        cout << endl;
        total++;
    }

    void displayLocations()
    {
        if (total == 0)
        {
            cout << "No locations available!\n";
            return;
        }

        cout << "\n--- Road Network Locations ---\n";
        for (int i = 0; i < total; i++)
        {
            cout << i << " : " << name[i];
            cout << (isHospital[i] ? " [Hospital]" : " [Junction]");
            cout << endl;
        }
    }

    void addRoad()
    {
        if (total < 2)
        {
            cout << "Add at least two locations first!\n";
            return;
        }

        int a, b, distance;
        displayLocations();
        cout << "Enter first location ID: ";
        cin >> a;
        cout << "Enter second location ID: ";
        cin >> b;

        if (a < 0 || a >= total || b < 0 || b >= total || a == b)
        {
            cout << "Invalid location IDs!\n";
            return;
        }

        cout << "Enter road distance in kilometres: ";
        cin >> distance;

        if (distance <= 0)
        {
            cout << "Distance must be positive!\n";
            return;
        }

        road[a][b] = distance;
        road[b][a] = distance;
        cout << "Road added: " << name[a] << " <--> " << name[b]
             << " (" << distance << " km)\n";
    }

    void displayRoads()
    {
        if (total == 0)
        {
            cout << "No locations available!\n";
            return;
        }

        cout << "\n--- Road Distance Matrix (km) ---\n    ";
        for (int i = 0; i < total; i++)
            cout << setw(6) << i;
        cout << endl;

        for (int i = 0; i < total; i++)
        {
            cout << setw(3) << i << " ";
            for (int j = 0; j < total; j++)
            {
                if (road[i][j] == INF)
                    cout << setw(6) << "-";
                else
                    cout << setw(6) << road[i][j];
            }
            cout << endl;
        }
        cout << "Rows/columns use location IDs. '-' means no direct road.\n";
    }

    void shortestRoute()
    {
        if (total == 0)
        {
            cout << "No locations available!\n";
            return;
        }

        int start;
        displayLocations();
        cout << "Enter ambulance starting location ID: ";
        cin >> start;

        if (start < 0 || start >= total)
        {
            cout << "Invalid location ID!\n";
            return;
        }

        int dist[MAX], parent[MAX], visited[MAX];
        for (int i = 0; i < total; i++)
        {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = 0;
        }
        dist[start] = 0;

        for (int step = 0; step < total; step++)
        {
            int u = -1;
            int best = INF;

            for (int i = 0; i < total; i++)
            {
                if (!visited[i] && dist[i] < best)
                {
                    best = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = 1;

            for (int v = 0; v < total; v++)
            {
                if (!visited[v] && road[u][v] != INF &&
                    dist[u] + road[u][v] < dist[v])
                {
                    dist[v] = dist[u] + road[u][v];
                    parent[v] = u;
                }
            }
        }

        int hospital = -1;
        int bestDistance = INF;

        for (int i = 0; i < total; i++)
        {
            if (isHospital[i] && dist[i] < bestDistance)
            {
                bestDistance = dist[i];
                hospital = i;
            }
        }

        if (hospital == -1 || bestDistance == INF)
        {
            cout << "No reachable hospital found from this location.\n";
            return;
        }

        int path[MAX], count = 0, current = hospital;
        while (current != -1 && count < MAX)
        {
            path[count++] = current;
            current = parent[current];
        }

        cout << "\n--- Shortest Ambulance Route ---\n";
        cout << "Starting location: " << name[start] << endl;
        cout << "Nearest reachable hospital: " << name[hospital] << endl;
        cout << "Route: ";
        for (int i = count - 1; i >= 0; i--)
        {
            cout << name[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\nTotal distance: " << bestDistance << " km\n";
    }
};

int main()
{
    RoadNetwork network;
    int choice;

    do
    {
        cout << "\n===== AMBULANCE ROUTE MANAGEMENT =====\n";
        cout << "1. Add Junction/Hospital\n";
        cout << "2. Add Road with Distance\n";
        cout << "3. Display Locations\n";
        cout << "4. Display Road Distance Matrix\n";
        cout << "5. Find Shortest Route to a Hospital (Dijkstra)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: network.addLocation(); break;
            case 2: network.addRoad(); break;
            case 3: network.displayLocations(); break;
            case 4: network.displayRoads(); break;
            case 5: network.shortestRoute(); break;
            case 6: cout << "Program terminated. Stay safe!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

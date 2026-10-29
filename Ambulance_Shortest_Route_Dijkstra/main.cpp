#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Road {
    int to;
    int distance;
};

int findLocation(const vector<string>& names, const string& name) {
    for (int i = 0; i < (int)names.size(); i++)
        if (names[i] == name) return i;
    return -1;
}

int main() {
    int n, m;
    cout << "=== Ambulance Shortest Route using Dijkstra's Algorithm ===\n";
    cout << "Enter number of locations (junctions/hospitals): ";
    if (!(cin >> n) || n <= 0) { cout << "Invalid number.\n"; return 1; }

    vector<string> names(n);
    cout << "Enter unique location names (one word each):\n";
    for (int i = 0; i < n; i++) {
        cout << "Location " << i + 1 << ": ";
        cin >> names[i];
        for (int j = 0; j < i; j++) {
            if (names[i] == names[j]) { cout << "Location names must be unique.\n"; return 1; }
        }
    }

    vector< vector<Road> > graph(n);
    cout << "Enter number of roads: ";
    if (!(cin >> m) || m < 0) { cout << "Invalid number of roads.\n"; return 1; }

    cout << "Enter each road as: location1 location2 distance\n";
    for (int i = 0; i < m; i++) {
        string a, b;
        int d;
        cout << "Road " << i + 1 << ": ";
        cin >> a >> b >> d;
        int u = findLocation(names, a), v = findLocation(names, b);
        if (u == -1 || v == -1) { cout << "Unknown location.\n"; return 1; }
        if (d < 0) { cout << "Distance cannot be negative.\n"; return 1; }
        Road r1; r1.to = v; r1.distance = d;
        Road r2; r2.to = u; r2.distance = d;
        graph[u].push_back(r1);
        graph[v].push_back(r2);
    }

    string startName, hospitalName;
    cout << "Enter ambulance starting location: ";
    cin >> startName;
    cout << "Enter destination hospital: ";
    cin >> hospitalName;

    int start = findLocation(names, startName);
    int target = findLocation(names, hospitalName);
    if (start == -1 || target == -1) { cout << "Unknown starting location or hospital.\n"; return 1; }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1), used(n, 0);
    dist[start] = 0;

    // O(V^2 + E) Dijkstra: compatible with older Dev-C++.
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u])) u = i;

        if (u == -1 || dist[u] == INF) break;
        used[u] = 1;
        if (u == target) break;

        for (int j = 0; j < (int)graph[u].size(); j++) {
            int v = graph[u][j].to;
            long long nd = dist[u] + graph[u][j].distance;
            if (!used[v] && nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
            }
        }
    }

    if (dist[target] == INF) {
        cout << "No route exists from " << startName << " to " << hospitalName << ".\n";
        return 0;
    }

    vector<int> path;
    int at = target;
    while (at != -1) { path.push_back(at); at = parent[at]; }

    cout << "\nShortest route for the ambulance:\n";
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << names[path[i]];
        if (i > 0) cout << " -> ";
    }
    cout << "\nTotal distance: " << dist[target] << " units\n";
    return 0;
}

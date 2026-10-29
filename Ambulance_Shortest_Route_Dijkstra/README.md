Ambulance Shortest Route using Dijkstra's Algorithm

Problem Statement

To develop a weighted road network representing hospitals and road junctions, and apply Dijkstra's Algorithm to determine the shortest-distance route for an ambulance to reach a hospital.

Objective

To implement Dijkstra's Algorithm in C++ to find the shortest route from the ambulance's starting location to the destination hospital.

Data Structure Used

- Graph
- Adjacency List
- Vector

Operations

- Enter the number of locations.
- Enter unique names of locations.
- Enter roads with their distances.
- Select the ambulance's starting location.
- Enter the destination hospital.
- Calculate the shortest route.
- Display the shortest route and total distance.
- Display a message if no route exists.

Concepts Used

- C++
- Graph
- Dijkstra's Algorithm
- Weighted Graph
- Adjacency List
- Vectors
- Structures
- Shortest Path
- Greedy Algorithm

Algorithm

1. Start the program.
2. Enter the number of locations and their unique names.
3. Enter the number of roads and the distance between connected locations.
4. Create a weighted graph using an adjacency list.
5. Enter the ambulance's starting location and destination hospital.
6. Initialize the distance of the starting location to zero and all other locations to infinity.
7. Select the unvisited location with the minimum distance.
8. Update the distances of its connected locations if a shorter route is found.
9. Repeat until the destination is reached or no reachable locations remain.
10. Reconstruct and display the shortest route using parent locations.
11. Display the total distance or a message if no route exists.
12. Stop the program.

Advantages

- Finds the shortest-distance route to a hospital.
- Helps in planning ambulance routes.
- Supports weighted roads with different distances.
- Displays the complete route and total distance.
- Detects when no route is available between two locations.

Conclusion

The Ambulance Shortest Route System demonstrates the implementation of Dijkstra's Algorithm using a weighted graph in C++. It finds the shortest-distance route from an ambulance's starting location to a destination hospital and displays the total distance. This project helps in understanding graphs, adjacency lists, greedy algorithms, and shortest-path techniques.

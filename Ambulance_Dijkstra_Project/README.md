# Ambulance Route Management Using Dijkstra's Algorithm

## Problem Statement
Develop a weighted road network representing hospitals and road junctions, and apply Dijkstra's algorithm to determine the shortest-distance route for an ambulance to reach a hospital.

## Project Overview
This menu-driven C++ project represents road junctions and hospitals as vertices in an undirected weighted graph. Roads are edges, and each edge stores the road distance in kilometres. Dijkstra's algorithm finds the minimum-distance route from a selected ambulance starting point to the nearest reachable hospital.

## Features
1. Add road junctions and hospitals.
2. Add roads with distance in kilometres.
3. Display all locations and their types.
4. Display the road distance matrix.
5. Find the shortest route to the nearest reachable hospital using Dijkstra's algorithm.
6. Display the route and total distance.

## Data Structures and Algorithm
- Graph representation: Adjacency matrix
- Algorithm: Dijkstra's shortest-path algorithm
- Vertices: Road junctions and hospitals
- Weighted edges: Road distances in kilometres
- Parent array: Reconstructs the shortest route

## Requirements
- Dev-C++ or another C++ compiler
- Standard C++ headers only; no external libraries

## How to Run in Dev-C++
1. Download and extract this ZIP file.
2. Open `ambulance_dijkstra.cpp` in Dev-C++.
3. Select **Execute -> Compile & Run**.
4. Add locations first, marking hospitals as type 2.
5. Add roads and enter positive distances.
6. Select option 5 and enter the ambulance's starting location ID.

## Example Network
Add these locations:
- ID 0: Central Junction (Road Junction)
- ID 1: Market Junction (Road Junction)
- ID 2: Civil Hospital (Hospital)
- ID 3: Bus Stand Junction (Road Junction)
- ID 4: City Hospital (Hospital)

Add these roads:
- 0 to 1: 4 km
- 0 to 3: 2 km
- 1 to 2: 5 km
- 3 to 2: 2 km
- 3 to 4: 7 km
- 1 to 4: 6 km

From Central Junction (ID 0), the shortest route to a hospital is:
`Central Junction -> Bus Stand Junction -> Civil Hospital`
Total distance: `4 km`

## Complexity
For an adjacency matrix implementation:
- Time complexity of Dijkstra's algorithm: O(V^2)
- Graph storage: O(V^2)

## Important Note
This is an educational demonstration. The route is based only on the distances entered by the user. It does not use live traffic, road closures, ambulance priority signals, or real map data.

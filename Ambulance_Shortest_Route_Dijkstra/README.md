# Ambulance Shortest Route using Dijkstra's Algorithm

C++98-compatible Dev-C++ version. This implementation uses the simple `O(V^2 + E)` form of Dijkstra's algorithm to avoid modern C++ library features.

## Run
Open `main.cpp` in Dev-C++ and select **Execute > Compile & Run**.

## Sample input
```text
6
J1
J2
J3
J4
J5
HospitalA
8
J1 J2 4
J1 J3 2
J2 J3 1
J2 J4 5
J3 J4 8
J3 J5 10
J4 HospitalA 2
J5 HospitalA 3
J1
HospitalA
```

Expected shortest route: `J1 -> J3 -> J2 -> J4 -> HospitalA` with distance `10` units. Distances are illustrative.

## Complexity
Time: `O(V^2 + E)`. Space: `O(V + E)`.

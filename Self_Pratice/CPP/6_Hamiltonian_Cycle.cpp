#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTICES = 10; // Maximum number of vertices

vector<int> path; // Stores the Hamiltonian cycle path
bool visited[MAX_VERTICES]; // Keeps track of visited vertices

bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int pos, int V) {
    // Check if the vertex can be added to the path
    if (graph[path[pos - 1]][vertex] == 0)
        return false;

    // Check if the vertex has already been visited
    for (int i = 0; i < pos; i++) {
        if (path[i] == vertex)
            return false;
    }

    return true;
}

void hamiltonianCycleUtil(int graph[MAX_VERTICES][MAX_VERTICES], int pos, int V, int count) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if the last vertex is connected to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            // Print the Hamiltonian cycle
            cout << "Hamiltonian Cycle " << count << ": ";
            for (int i = 0; i < V; i++)
                cout << path[i] << " ";
            cout << path[0] << endl;
            count++;
        }
        return;
    }

    // Try adding each vertex to the path
    for (int vertex = 0; vertex < V; vertex++) {
        if (isSafe(vertex, graph, pos, V)) {
            path[pos] = vertex;
            visited[vertex] = true;

            hamiltonianCycleUtil(graph, pos + 1, V, count);

            // Backtrack
            visited[vertex] = false;
            path[pos] = -1;
        }
    }
}

void hamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    path.resize(V, -1); // Initialize path vector with -1
    path[0] = 0; // Start with the first vertex
    visited[0] = true; // Mark the first vertex as visited

    int count = 1; // Counter for the number of Hamiltonian cycles
    hamiltonianCycleUtil(graph, 1, V, count);

    if (count == 1) {
        cout << "No More Hamiltonian Cycles found" << endl;
    } else {
        cout << "Total Hamiltonian Cycles: " << count - 1 << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX_VERTICES][MAX_VERTICES];

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    hamiltonianCycle(graph, V);

    return 0;
}
/*
5
0 1 1 0 1
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/
#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 100; // Maximum number of vertices in the graph

void BFS(int graph[][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Track visited vertices
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";

        // Visit all adjacent vertices of the current vertex
        for (int adjVertex = 0; adjVertex < numVertices; adjVertex++) {
            if (graph[currVertex][adjVertex] == 1 && !visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
}

void displayGraph(int graph[][MAX_VERTICES], int numVertices) {
    cout << "Graph Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cout << "Enter the edges (source destination):";
        cin >> source >> destination;

        // Assuming an undirected graph
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    //displayGraph(graph, numVertices);

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(graph, numVertices, startVertex);

    return 0;
}

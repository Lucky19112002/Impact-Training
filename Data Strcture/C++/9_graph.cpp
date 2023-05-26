#include <iostream>
#include <vector>

const int MAX_SIZE = 10; // Maximum number of vertices in the graph

using namespace std;

void initializeGraph(int graph[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0; // Initialize all elements to 0 (no edges)
        }
    }
}

void addEdge(int graph[][MAX_SIZE], int source, int destination) {
    // Assuming the graph is undirected, we set both source -> destination and destination -> source as 1 (indicating an edge)
    graph[source][destination] = 1;
    graph[destination][source] = 1;
}

void printGraph(int graph[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void createAdjacencyList(int graph[][MAX_SIZE], int size, vector<vector<int>>& adjList) {
    adjList.resize(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }
}

void printAdjacencyList(const vector<vector<int>>& adjList) {
    int size = adjList.size();
    for (int i = 0; i < size; i++) {
        cout << "Vertex " << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE];
    int size; // Number of vertices in the graph

    cout << "Enter the number of vertices in the graph: ";
    cin >> size;

    initializeGraph(graph, size);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int source, destination;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> source >> destination;
        addEdge(graph, source, destination);
    }

    cout << "Adjacency Matrix:\n";
    printGraph(graph, size);

    vector<vector<int>> adjList;
    createAdjacencyList(graph, size, adjList);

    cout << "Adjacency List:\n";
    printAdjacencyList(adjList);

    return 0;
}

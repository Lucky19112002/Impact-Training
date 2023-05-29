#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MAX_SIZE = 10; // Maximum number of vertices in the graph

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

void depthFirstSearch(int graph[][MAX_SIZE], int size, int startVertex) {
    stack<int> stack;
    bool visited[MAX_SIZE] = { false };

    visited[startVertex] = true;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        cout << currentVertex + 1 << " ";

        // Visit all the adjacent vertices of the current vertex
        for (int i = 0; i < size; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                stack.push(i);
            }
        }
    }
}

void breadthFirstSearch(int graph[][MAX_SIZE], int size, int startVertex) {
    queue<int> queue;
    bool visited[MAX_SIZE] = { false };

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        cout << currentVertex + 1 << " ";

        // Visit all the adjacent vertices of the current vertex
        for (int i = 0; i < size; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

void printAdjList(int graph[][MAX_SIZE], int size) {
    vector<vector<int>> adjList(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << "Vertex " << i + 1 << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] + 1 << " "; // Adjust the indexing by adding 1
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
        addEdge(graph, source - 1, destination - 1); 
    }

    cout << "Adjacency Matrix:\n";
    printGraph(graph, size);

    cout << "Adjacency List:\n";
    printAdjList(graph, size);

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;
    startVertex--; 

    cout << "DFS Traversal: ";
    depthFirstSearch(graph, size, startVertex);

    cout << endl;

    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;
    startVertex--; 

    cout << "BFS Traversal: ";
    breadthFirstSearch(graph, size, startVertex);

    return 0;
}

#include <iostream>
using namespace std;

bool isSafe(int** maze, int size, int x, int y) {
    // Check if the current position is valid
    return (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1);
}

bool solveMazeUtil(int** maze, int size, int x, int y, int** sol) {
    // Base case: If the rat reaches the destination
    if (x == size - 1 && y == size - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if the current position is valid
    if (isSafe(maze, size, x, y)) {
        // Mark the current cell as part of the solution path
        sol[x][y] = 1;

        // Move to the right direction
        if (solveMazeUtil(maze, size, x + 1, y, sol))
            return true;

        // Move to the down direction
        if (solveMazeUtil(maze, size, x, y + 1, sol))
            return true;

        // Move to the left direction
        if (solveMazeUtil(maze, size, x, y - 1, sol))
            return true;

        // Move to the up direction
        if (solveMazeUtil(maze, size, x - 1, y, sol))
            return true;

        // If none of the above movements work, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int** maze, int size, int startX, int startY) {
    int** sol = new int*[size];
    for (int i = 0; i < size; i++) {
        sol[i] = new int[size];
        for (int j = 0; j < size; j++) {
            sol[i][j] = 0;
        }
    }

    if (solveMazeUtil(maze, size, startX, startY, sol)) {
        // Print the solution path
        cout << "Path found!" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }

    // Deallocate memory
    for (int i = 0; i < size; i++) {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;
}

int main() {
    int size, startX, startY;

    // Get the size of the matrix from the user
    cout << "Enter the size of the matrix: ";
    cin >> size;

    // Create the maze matrix and input the values from the user
    int** maze = new int*[size];
    cout << "Enter the matrix values (0 or 1):" << endl;
    for (int i = 0; i < size; i++) {
        maze[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> maze[i][j];
        }
    }

    // Get the starting position of the rat from the user
    cout << "Enter the starting x index of the rat: ";
    cin >> startX;
    cout << "Enter the starting y index of the rat: ";
    cin >> startY;

    solveMaze(maze, size, startX, startY);

    return 0;
}


/*
5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
self example
6
1 1 1 1 1 1
0 0 0 0 1 0
0 1 1 0 1 0
0 1 1 1 1 0
0 1 0 0 0 0
0 1 1 1 1 1
*/
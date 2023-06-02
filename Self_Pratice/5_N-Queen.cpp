#include<iostream>
using namespace std;

// Function to check if it is safe to place a queen at position (x, y)
// in the current arrangement of queens
bool isSafe(int** arr, int x, int y, int n) {
    // Check if there is a queen in the same column
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    // Check if there is a queen in the upper-right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

// Recursive function to solve the N-Queen problem
bool nQueen(int** arr, int x, int n) {
    // Base case: If all queens are placed successfully
    if (x == n)
        return true;

    // Try placing the queen at each column in the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(arr, x, col, n)) {
            // Place the queen at position (x, col)
            arr[x][col] = 1;

            // Recursively place the rest of the queens
            if (nQueen(arr, x + 1, n)) {
                return true;
            }

            // If placing the queen at (x, col) doesn't lead to a solution,
            // backtrack by removing the queen from (x, col)
            arr[x][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    // Dynamically allocate a 2D array of size n x n and initialize with 0
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    cout << "Solution is : \n";
    if (nQueen(arr, 0, n)) {
        // Print the arrangement of queens
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // Deallocate the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

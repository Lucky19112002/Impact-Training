#include <iostream>

using namespace std;

int backtrack(int** grid, int** memo, int row, int col, int m, int n) {
    // Base cases
    if (row < 0 || row >= m || col < 0 || col >= n) {
        return 0;
    }

    // Check if the value is already computed
    if (memo[row][col] != 0) {
        return memo[row][col];
    }

    // Move left, left-up, or left-down and find the maximum gold
    int left = backtrack(grid, memo, row, col - 1, m, n);
    int leftUp = backtrack(grid, memo, row - 1, col - 1, m, n);
    int leftDown = backtrack(grid, memo, row + 1, col - 1, m, n);

    // Find the maximum of the three directions
    int maxGold = max(left, max(leftUp, leftDown));

    // Add the current cell's gold to the maximum
    memo[row][col] = maxGold + grid[row][col];

    return memo[row][col];
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    int** grid = new int*[m];
    for (int i = 0; i < m; i++) {
        grid[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int** memo = new int*[m];
    for (int i = 0; i < m; i++) {
        memo[i] = new int[n];
        for (int j = 0; j < n; j++) {
            memo[i][j] = 0;  // Initialize memoization array with 0
        }
    }

    // Perform backtracking from the last column
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        int currentGold = backtrack(grid, memo, i, n - 1, m, n);
        maxGold = max(maxGold, currentGold);
    }

    cout << "Maximum gold that can be collected: " << maxGold << endl;

    // Deallocate memory
    for (int i = 0; i < m; i++) {
        delete[] grid[i];
        delete[] memo[i];
    }
    delete[] grid;
    delete[] memo;

    return 0;
}
/*
3 4
5  6  2  8
4  2  9  1
9  7  3  5
*/
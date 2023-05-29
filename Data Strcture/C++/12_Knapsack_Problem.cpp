#include <iostream>
using namespace std;

void printMatrix(int **dp, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int knapSack(int capacity, int weights[], int values[], int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printMatrix(dp, n + 1, capacity + 1);
    return dp[n][capacity];
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int max_value = knapSack(capacity, weights, values, n);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}

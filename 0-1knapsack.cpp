#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
};

class ZeroOneKnapsack
{
public:
    int Recursion(Item arr[], int W, int N) // Time O(2^n) Space O(1)
    {
        if (N == 0 || W == 0)
            return 0;

        if (W >= arr[N - 1].weight)
        {
            return max(arr[N - 1].value + Recursion(arr, W - arr[N - 1].weight, N - 1), Recursion(arr, W, N - 1));
        }

        return Recursion(arr, W, N - 1);
    }

    int Memoization(Item arr[], int W, int N, vector<vector<int>> &dp) // Time O(N*W) Space O(N*W)
    {
        if (N == 0 || W == 0)
            return dp[N][W] = 0;

        if (dp[N][W] != -1)
            return dp[N][W];

        if (W >= arr[N - 1].weight)
        {
            return dp[N][W] = max(arr[N - 1].value + Memoization(arr, W - arr[N - 1].weight, N - 1, dp), Memoization(arr, W, N - 1, dp));
        }

        return dp[N][W] = Recursion(arr, W, N - 1);
    }

    int BottomUp(Item arr[], int W, int N) // Time O(N*W) Space O(N*W)
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1));

        for (int i = 0; i <= W; i++)
            dp[0][i] = 0;

        for (int i = 0; i <= N; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (j >= arr[i - 1].weight)
                    dp[i][j] = max(arr[i - 1].value + dp[i - 1][j - arr[i - 1].weight], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][W];
    }

    int spaceOptimizedDP(Item arr[], int W, int N) // Time O(N*W) Space O(W)
    {
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < N; i++)
        {
            for (int j = W; j >= arr[i].weight; j--)
            {
                dp[j] = max(dp[j], arr[i].value + dp[j - arr[i].weight]);
            }
        }

        return dp[W];
    }
};

int main()
{
    int n;
    cin >> n;

    Item arr[n];
    int x, y, W;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr[i].value = x;
        arr[i].weight = y;
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    ZeroOneKnapsack obj;
    cout << obj.Recursion(arr, W, n);
    cout << obj.Memoization(arr, W, n, dp);
    cout << obj.BottomUp(arr, W, n);
    cout << obj.spaceOptimizedDP(arr, W, n);
}
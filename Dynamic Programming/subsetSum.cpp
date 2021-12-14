#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subsetSum(int arr[], int Sum, int N) // Time O(N*Sum) Space O(N*Sum)
    {
        vector<vector<bool>> dp(N + 1, vector<bool>(Sum + 1));

        for (int i = 0; i <= Sum; i++)
            dp[0][i] = false;

        for (int i = 0; i <= N; i++)
            dp[i][0] = true;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= Sum; j++)
            {
                if (j >= arr[i - 1])
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][Sum];
    }

    bool spaceOptimizedDP(int arr[], int Sum, int N) // Time O(N*Sum) Space O(Sum)
    {
        vector<bool> dp(Sum + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = Sum; j >= arr[i]; j--)
            {
                dp[j] = (dp[j] || dp[j - arr[i]]);
            }
        }

        return dp[Sum];
    }
};

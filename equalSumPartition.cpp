#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool equalSumPartition(int arr[], int N) // Time O(N*Sum) Space O(N*Sum)
    {
        int Sum = 0;
        for (int i = 0; i < N; i++)
        {
            Sum += arr[i];
        }

        if (Sum & 1)
            return false;

        int partitionSum = Sum / 2;

        vector<vector<bool>> dp(N + 1, vector<bool>(partitionSum + 1));

        for (int i = 0; i <= partitionSum; i++)
            dp[0][i] = false;

        for (int i = 0; i <= N; i++)
            dp[i][0] = true;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= partitionSum; j++)
            {
                if (j >= arr[i - 1])
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][partitionSum];
    }

    bool spaceOptimizedDP(int arr[], int N) // Time O(N*Sum) Space O(Sum)
    {
        int Sum = 0;
        for (int i = 0; i < N; i++)
        {
            Sum += arr[i];
        }

        if (Sum & 1)
            return false;

        int partitionSum = Sum / 2;

        vector<bool> dp(partitionSum + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = partitionSum; j >= arr[i]; j--)
            {
                dp[j] = (dp[j] || dp[j - arr[i]]);
            }
        }

        return dp[partitionSum];
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDiffPartition(int arr[], int N) // Time O(N * Sum/2), Space O(N * Sum/2)
    {
        long Sum = 0;
        for (int i = 0; i < N; i++)
        {
            Sum += arr[i];
        }

        long partitionSum = Sum / 2;

        vector<vector<bool>> dp(N + 1, vector<bool>(partitionSum + 1));

        for (int i = 0; i <= N; i++)
            dp[i][0] = true;
        for (int i = 1; i <= partitionSum; i++)
            dp[0][i] = false;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= partitionSum; j++)
            {
                if (j >= arr[i - 1])
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        long maxPartitionSubsetSum;
        for (int i = partitionSum; i >= 0; i--)
        {
            if (dp[N][i])
            {
                maxPartitionSubsetSum = i;
                break;
            }
        }

        long ans = Sum - 2 * maxPartitionSubsetSum;
        return ans;
    }

    int spaceOptimizedDP(int arr[], int N) // Time O(N * Sum), Space O(Sum/2)
    {
        long Sum = 0;
        for (int i = 0; i < N; i++)
        {
            Sum += arr[i];
        }

        long partitionSum = Sum / 2;

        vector<bool> dp(partitionSum + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = partitionSum; j >= arr[i]; j--)
            {
                dp[j] = (dp[j] || dp[j - arr[i]]);
            }
        }

        long maxPartitionSubsetSum;
        for (int i = partitionSum; i >= 0; i--)
        {
            if (dp[i])
            {
                maxPartitionSubsetSum = i;
                break;
            }
        }

        long ans = Sum - 2 * maxPartitionSubsetSum;
        return ans;
    }
};

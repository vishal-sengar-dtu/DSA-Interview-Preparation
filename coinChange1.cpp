#include <bits/stdc++.h>
using namespace std;

class CoinChange
{
public:
    bool noOfWays(int coins[], int Sum, int N) // Time O(N*Sum) Space O(N*Sum)
    {
        vector<vector<long>> dp(N + 1, vector<long>(Sum + 1));

        for (int i = 0; i <= Sum; i++)
            dp[0][i] = 0;

        for (int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= Sum; j++)
            {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][Sum];
    }

    bool spaceOptimizedDP(int coins[], int Sum, int N) // Time O(N*Sum) Space O(Sum)
    {
        vector<long> dp(Sum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j <= Sum; j++)
            {
                if (j >= coins[i])
                    dp[j] = (dp[j] || dp[j - coins[i]]);
            }
        }

        return dp[Sum];
    }
};

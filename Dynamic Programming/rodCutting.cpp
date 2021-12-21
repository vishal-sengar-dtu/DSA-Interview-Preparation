#include <bits/stdc++.h>
using namespace std;

class RodCutting // (https://practice.geeksforgeeks.org/problems/rod-cutting0840/1)
{
public:
    int BottomUp(int price[], int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j >= i)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - i] + price[i - 1]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][N];
    }

    int spaceOptimizedDP(int price[], int N)
    {
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j >= i)
                {
                    dp[j] = max(dp[j], dp[j - (i)] + price[i - 1]);
                }
            }
        }
        return dp[N];
    }
};

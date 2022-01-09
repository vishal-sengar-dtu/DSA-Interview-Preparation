#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/dungeon-game/)
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) // Time O(N * M), Space O(N * M)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // 2-D DP matrix with base condition
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int reqHP = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                dp[i][j] = reqHP > 0 ? reqHP : 1;
            }
        }

        return dp[0][0];
    }

    // Space Optimized
    int calculateMinimumHP(vector<vector<int>> &dungeon) // Time O(N * M), Space O(N)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> dp(n + 1, INT_MAX);

        // base case
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int reqHP = min(dp[j], dp[j + 1]) - dungeon[i][j];
                dp[j] = reqHP > 0 ? reqHP : 1;
            }
        }
        return dp[0];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution // (https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)
{
public:
    int longestRepeatingSubsequence(string s) // Time O(N * N), Space O(N * N)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // If the matched character is having different index then only the subsequence is repeating.
                if (s[i - 1] == s[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }

    int spaceOptimizedDP(string s) // Time O(N * N), Space O(N)
    {
        int n = s.length();
        vector<int> dp(n + 1);
        int prev_val, curr_val;

        for (int i = 1; i <= n; i++)
        {
            prev_val = 0;
            for (int j = 1; j <= n; j++)
            {
                curr_val = dp[j];

                if (s[i - 1] == s[j - 1] && i != j)
                    dp[j] = 1 + prev_val;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prev_val = curr_val;
            }
        }
        return dp[n];
    }
};
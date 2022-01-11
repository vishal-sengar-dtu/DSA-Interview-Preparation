#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Amazon, Goldman Sachs, Microsoft, Google}
    Question Link : {https://leetcode.com/problems/edit-distance/}
*/

class EditDistance
{
    int helper(string s1, string s2, int n, int m) // Exponential Time Complexity TLE
    {
        // if length of strings are not equal, we have to insert or delete the remaining characters.
        if (n == 0 || m == 0)
            return abs(n - m);

        // if characters are same we need not to perform any operation.
        if (s1[n - 1] == s2[m - 1])
            return helper(s1, s2, n - 1, m - 1);

        else
        {
            int ins = 1 + helper(s1, s2, n, m - 1);

            int del = 1 + helper(s1, s2, n - 1, m);

            int rep = 1 + helper(s1, s2, n - 1, m - 1);

            return min(ins, min(del, rep));
        }
    }

    int memo(string s1, string s2, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return dp[n][m] = abs(n - m);

        // memoization - returning solution to already solved subproblems.
        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = memo(s1, s2, n - 1, m - 1, dp);

        else
        {
            return dp[n][m] = min(1 + memo(s1, s2, n, m - 1, dp),
                                  min(1 + memo(s1, s2, n - 1, m, dp),
                                      1 + memo(s1, s2, n - 1, m - 1, dp)));
        }
    }

public:
    int recursion(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        int ans = helper(s1, s2, n, m);
        return ans;
    }

    int memoization(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = memo(s1, s2, n, m, dp);
        return ans;
    }

    int bottomUp(string s1, string s2) // Time O(N * M), Space O(N * M)
    {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
            dp[i][0] = i;

        for (int j = 1; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        return dp[n][m];
    }
};
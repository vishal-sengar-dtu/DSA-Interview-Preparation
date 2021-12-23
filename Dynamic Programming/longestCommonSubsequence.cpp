#include <bits/stdc++.h>
using namespace std;

class LCS // (https://leetcode.com/problems/longest-common-subsequence/)
{
    int helper(string s1, string s2, int n, int m)
    {
        // If length of any string is 0 then nothing is common
        if (n == 0 || m == 0)
            return 0;

        if (s1[n - 1] == s2[m - 1])
            return 1 + helper(s1, s2, n - 1, m - 1);
        else
            return max(helper(s1, s2, n, m - 1), helper(s1, s2, n - 1, m));
    }

public:
    int lcs(string s1, string s2) // Exponential Time Complexity
    {
        int n = s1.length();
        int m = s2.length();
        cout << helper(s1, s2, n, m);
    }

    int bottomUp(string s1, string s2) // Time O(N * M), Space (N * M)
    {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // base condition - length of either on them is zero
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int spaceOptimized(string s1, string s2) // Time O(N * M), Space O(min(N, M))
    {
        int n = s1.length();
        int m = s2.length();

        vector<int> dp(m, 0);
        int prev_val, curr_val;

        for (int i = 1; i <= n; i++)
        {
            prev_val = 0;
            for (int j = 1; j <= m; j++)
            {
                // storing the curr_val before updation for next iteration
                curr_val = dp[j];

                dp[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev_val : max(dp[j - 1], dp[j]);

                // this is representing the dp[i-1][j-1]
                prev_val = curr_val;
            }
        }
        return dp[m];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution // (return the LCS string)
{
public:
    string printLCS(string s1, string s2) // Time O(N * M), Space (N * M)
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

        int i = n, j = m;
        string lcs = "";

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs += s1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
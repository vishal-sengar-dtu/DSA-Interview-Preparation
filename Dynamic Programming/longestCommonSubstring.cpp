#include <bits/stdc++.h>
using namespace std;

class Solution // (https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1)
{
public:
    int longestCommonSubstring(string s1, string s2) // Time O(N * M), Space (N * M)
    {
        int n = s1.length();
        int m = s2.length();
        int mxLen = 0;

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
                // If consicutive characters are equal then we keep increasing the length and update the mxLen.
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mxLen = max(dp[i][j], mxLen);
                }
                // if two characters are not equal then continuity breaks and we set the mxLen back to 0.
                else
                    dp[i][j] = 0;
            }
        }
        return mxLen;
    }
};
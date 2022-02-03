#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Amazon, Groupon, Microsoft, Qualcomm, Samsung, Visa, Walmart, Zoho}
    Question Link : {https://leetcode.com/problems/longest-palindromic-substring/}
*/

class Solution
{
public:
    string longestPalindrome(string s) // Method 1 => Dynamic Programming
    {
        int n = s.length(), len = 0, idx;

        int dp[n + 1][n + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (s[i - 1] == s[n - j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > len)
                    {
                        len = dp[i][j];
                        idx = i - 1;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        string ans = "";
        ans = s.substr(idx - len + 1, len);
        return ans;
    }

    string longestPalindrome(string s) // Method 2 => Expand from Centre
    {
    }
};
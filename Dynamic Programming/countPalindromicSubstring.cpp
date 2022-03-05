#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Amazon, Morgan Stanley, Ola Cabs, SAP Labs}
    Question Link : {https://leetcode.com/problems/palindromic-substrings/}
*/

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        bool table[n][n];
        memset(table, 0, sizeof(table));
        int ans = n;

        for (int i = 0; i < n; i++)
            table[i][i] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (s[j] == s[j + i])
                {
                    if (i == 1 || table[j + 1][j + i - 1])
                    {
                        table[j][j + i] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
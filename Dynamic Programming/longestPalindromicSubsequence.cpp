#include <bits/stdc++.h>
#include "longestCommonSubsequence.cpp"
using namespace std;

class Solution : public LCS // (https://leetcode.com/problems/longest-palindromic-subsequence/)
{
public:
    int longestPalindromicSubsequence(string s)
    {
        int n = s.length();
        string rev = "";

        // store reversed string
        for (int i = 0; i < n; i++)
            rev[i] = s[n - i -1];

        int lcsLen = lcs(s, rev); // longest common subsequence (LCS)

        // longest palindromic subsequence is the LCS of the string and its reverse.
        return lcsLen;
    }
};
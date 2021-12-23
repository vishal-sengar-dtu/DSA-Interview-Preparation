#include <bits/stdc++.h>
#include "longestCommonSubsequence.cpp"
using namespace std;

class SCS : public LCS // (https://leetcode.com/problems/shortest-common-supersequence/)
{
    //  input: s1 = "A G G T A B",  s2 = "G X T X A Y B"
    //  output: length - 9, string - "A G G X T X A Y B"

public:
    int shortestCommonSupersequenceLength(string s1, string s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        int lcsLength = lcs(s1, s2);

        return l1 + l2 - lcsLength;
    }

    string printShortestCommonSupersequence(string s1, string s2)
    {
    }
};
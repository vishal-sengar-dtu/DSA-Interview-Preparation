#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/roman-to-integer/)
{
    unordered_map<char, int> mp{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string str)
    {
        int ans = 0;
        for (int i = 0; i < str.length() - 1; i++)
        {
            if (mp[str[i]] >= mp[str[i + 1]])
                ans += mp[str[i]];
            else
                ans -= mp[str[i]];
        }
        ans += mp[str[str.length() - 1]];
        return ans;
    }
};
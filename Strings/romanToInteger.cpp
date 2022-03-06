#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/roman-to-integer/)
{
    unordered_map<char, int> roman{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string s)
    {
        int ans = roman[s[0]];
        for (int i = 1; i < s.length(); i++)
        {
            if (roman[s[i]] > roman[s[i - 1]])
                ans -= 2 * (roman[s[i - 1]]);
            ans += roman[s[i]];
        }
        return ans;
    }
};
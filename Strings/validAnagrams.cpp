#include<bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/valid-anagram/)
{
public:
    bool isAnagram(string s, string t) // Time O(N), Space O(1);
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();

        int chars[26] = {0};
        for (int i = 0; i < n; i++)
        {
            chars[s[i] - 'a']++;
            chars[t[i] - 'a']--;
        }

        for (int i : chars)
            if (i != 0)
                return false;

        return true;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/longest-substring-without-repeating-characters/)
{
public:
    int lengthOfLongestSubstring(string s) // Time O(N), Space O(N)
    {
        unordered_set<char> st;
        int left = 0, right = 0, n = s.size(), len = 0;

        while (left < n && right < n)
        {
            if (st.find(s[right]) == st.end())
            {
                st.insert(s[right++]);
                len = max(len, right - left);
            }
            else
                st.erase(s[left++]);
        }
        return len;
    }
};

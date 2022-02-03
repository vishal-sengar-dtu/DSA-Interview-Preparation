#include <bits/stdc++.h>
#include "validAnagrams.cpp"
using namespace std;

/*
    Company Tags : {Amazon, Intuit, Microsoft, Flipkart}
    Question Link : {https://leetcode.com/problems/find-all-anagrams-in-a-string/}
*/

class Solution : public Anagram
{
public:
    vector<int> findAnagrams(string s, string p) // Time O(N1 * N2), Space(N1 - N2)
    {
        vector<int> ans;
        int n1 = s.length(), n2 = p.length();

        for (int i = 0; i <= n1 - n2; i++)
        {
            if (isAnagram(s.substr(i, n2), p))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    /* Optimized Solution - Sliding Window */
    vector<int> findAnagrams(string s, string p) // Time O(N), Space O(1)
    {
        int s_len = s.length();
        int p_len = p.length();

        if (s.size() < p.size())
            return {};

        vector<int> freq_p(26, 0);
        vector<int> window(26, 0);

        // first window
        for (int i = 0; i < p_len; i++)
        {
            freq_p[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        vector<int> ans;
        if (freq_p == window)
            ans.push_back(0);

        for (int i = p_len; i < s_len; i++)
        {
            int beg = i - p_len;
            window[s[beg] - 'a']--;
            window[s[i] - 'a']++;

            if (freq_p == window)
                ans.push_back(beg + 1);
        }
        return ans;
    }
};
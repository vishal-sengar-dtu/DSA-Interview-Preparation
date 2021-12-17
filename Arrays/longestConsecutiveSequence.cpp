#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/longest-consecutive-sequence/)
{
public:
    int longestConsecutive(vector<int> &nums) // Time O(N), Space O(N)
    {
        unordered_map<int, bool> mp;
        int n = nums.size();

        // inserting all elements in the hashmap.
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = true;
        }

        // setting all values as false which are not the starting of any sequence.
        for (auto &it : mp)
        {
            if (mp.find(it.first - 1) != mp.end())
                mp[it.first] = false;
        }

        int mxLen = 0;
        for (auto &it : mp)
        {
            if (it.second)
            {
                int tmp = 1;
                while (mp.find(it.first + tmp) != mp.end())
                    tmp++;

                mxLen = max(mxLen, tmp);
            }
        }
        return mxLen;
    }
};
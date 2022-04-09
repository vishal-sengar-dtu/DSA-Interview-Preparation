#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/top-k-frequent-elements/)
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        vector<pair<int, int>> freq;
        for (auto it : mp)
            freq.push_back({it.second, it.first});

        sort(freq.begin(), freq.end(), comp);

        vector<int> ans;
        int i = 0;
        while (k--)
            ans.push_back(freq[i++].second);

        return ans;
    }
};
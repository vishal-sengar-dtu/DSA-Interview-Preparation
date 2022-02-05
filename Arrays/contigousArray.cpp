#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : { Amazon, MakeMyTrip, Morgan Stanley, Paytm}
    Question Link : {https://leetcode.com/problems/contiguous-array/}
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums) // Time O(N), Space O(N)
    {
        int ans = 0, sum = 0, len;
        unordered_map<int, int> mp;

        mp.insert({0, -1});

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] ? 1 : -1;
            if (mp.find(sum) != mp.end())
            {
                len = i - mp[sum];
                ans = max(ans, len);
            }
            else
            {
                mp.insert({sum, i});
            }
        }
        return ans;
    }
};
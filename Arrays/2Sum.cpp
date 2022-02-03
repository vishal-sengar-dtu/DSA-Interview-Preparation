#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/two-sum/)
{
private:
    unordered_map<int, int> mp;

    bool search(int n)
    {
        return mp.find(n) != mp.end();
    }

public:
    vector<int> twoSum(vector<int> &nums, int target) // Time O(N * N), Space O(1)
    {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n - 1; i++)
        {
            int temp = target - nums[i];

            for (int j = i + 1; j <= n; j++)
            {
                if (nums[j] == temp)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }

    vector<int> twoSumOptimized(vector<int> &nums, int target) // Time O(N), Space O(N)
    {
        int n = nums.size();
        vector<int> res{-1, -1};

        for (int i = 0; i < n; i++)
        {
            if (search(nums[i]))
            {
                res[0] = mp[nums[i]];
                res[1] = i;
                break;
            }
            mp.insert({target - nums[i], i});
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
        vector<int> result;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int temp = target - nums[i];

            if (mp.find(temp) != mp.end())
            {
                result.push_back(mp[temp]);
                result.push_back(i);
                break;
            }
            else
            {
                mp.insert({nums[i], i});
            }
        }
        return result;
    }
};
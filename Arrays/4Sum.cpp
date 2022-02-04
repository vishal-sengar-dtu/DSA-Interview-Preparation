#include <bits/stdc++.h>
using namespace std;

/*
Company Tags : {Adobe, Amazon, Google, Microsoft, OYO Rooms}
Question Link : {https://leetcode.com/problems/4sum/}
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((j > i + 1) && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1, r = nums.size() - 1;
                int new_target = target - nums[i] - nums[j];

                while (l < r)
                {
                    int sum = nums[l] + nums[r];

                    if (sum > new_target)
                        r--;
                    else if (sum < new_target)
                        l++;
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l++], nums[r--]});
                        while (l < r && nums[l] == nums[l - 1] && nums[r] == nums[r + 1])
                        {
                            l++;
                            r--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
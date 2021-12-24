#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/longest-increasing-subsequence/)
{
public:
    int lengthOfLIS(vector<int> &nums) // Time O(N * N), Space O(N)
    {
        int n = nums.size(), ans = 0;
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int len = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                    len = max(len, dp[j] + 1);
            }
            dp[i] = len;
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int LIS(vector<int> &nums)
    {
        int n = nums.size();
    }
};
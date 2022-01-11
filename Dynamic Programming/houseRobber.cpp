#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/house-robber/)
{
public:
    int helper(vector<int> &nums, int n)
    {
        if (n < 1)
            return 0;
        return max(nums[n - 1] + helper(nums, n - 2), helper(nums, n - 1));
    }

    int rob(vector<int> &nums) // Recursive Approch, Exponential Time Complexity
    {
        int n = nums.size();
        return helper(nums, n);
    }

    int rob(vector<int> &nums) // DP | Time O(N), Space O(N);
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }

    int rob(vector<int> &nums) // Space Optimized DP | Time O(N), Space O(1);
    {
        int n = nums.size();
        int a = 0, b = nums[0], c;

        for (int i = 2; i <= n; i++)
        {
            c = max(a + nums[i - 1], b);
            a = b;
            b = c;
        }
        return b;
    }
};
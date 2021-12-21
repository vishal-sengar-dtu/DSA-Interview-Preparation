#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/target-sum/)
{
public:
    int subsetSum(vector<int> &nums, int s) // Time O(N * N), Space O(target + arraySum)
    {
        int dp[s + 1] = {0};
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int arraySum = accumulate(nums.begin(), nums.end(), 0);

        return arraySum < target || (target + arraySum) & 1 ? 0 : subsetSum(nums, (target + arraySum) >> 1);
    }
};
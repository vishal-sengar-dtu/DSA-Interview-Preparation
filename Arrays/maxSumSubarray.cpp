#include <bits/stdc++.h>
using namespace std;

class MaxSumSubarray // (https://leetcode.com/problems/maximum-subarray/)
{
public:
    int kadane(int arr[], int n) // Time O(N), Space O(1)
    {
        int maxSum = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (maxSum < sum)
                maxSum = sum;

            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};
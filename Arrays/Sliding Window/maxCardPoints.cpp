#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
{
    int helper(int arr[], int first, int last, int k)
    {
        if (k == 0)
            return 0;

        return max(arr[first] + helper(arr, first + 1, last, k - 1), arr[last] + helper(arr, first, last - 1, k - 1));
    }

public:
    int recursive(int arr[], int n, int k) // Exponential (TLE)
    {
        return helper(arr, 0, n - 1, k);
    }

    int maxScore(int arr[], int n, int k) // Time O(N), Space O(1), sliding window approch
    {
        int sum, windowSum = 0, minWindowSum, windowSize = n - k;

        sum = accumulate(arr, arr, 0);

        for (int i = 0; i < windowSize; i++)
        {
            windowSum += arr[i];
        }

        minWindowSum = windowSum;

        for (int i = 0; i < n - windowSize; i++)
        {
            windowSum += arr[i + windowSize] - arr[i];
            minWindowSum = min(windowSum, minWindowSum);
        }

        return sum - minWindowSum;
    }
};
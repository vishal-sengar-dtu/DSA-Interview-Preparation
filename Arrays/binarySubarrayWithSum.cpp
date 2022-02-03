#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/binary-subarrays-with-sum/)
{
public:
    int prefixSum(int arr[], int n, int goal) // Time O(N), Space O(N)
    {
        unordered_map<int, int> mp; // For recording prefix sum
        int count = 0, sum = 0;
        mp[0]++;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            count += mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }

    int slidingWindow(int arr[], int n, int goal) // Time O(N), Space O(1)
    {
    }
};
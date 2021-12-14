#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/subarray-sum-equals-k/)
{
public:
    int subarraySum(int arr[], int n, int k) // Time O(N), Space O(N)
    {
        unordered_map<int, int> mp; // For recording prefix sum
        int count = 0, sum = 0;
        mp[0]++;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};

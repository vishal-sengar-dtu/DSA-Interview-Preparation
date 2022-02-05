#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : { Amazon }
    Question Link : {https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/}
*/

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K) // Time O(N), Space O(N)
    {
        int ans = 0, sum = 0, len;
        unordered_map<int, int> mp;

        mp.insert({0, -1});

        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (mp.find(sum) == mp.end())
                mp.insert({sum, i});

            if (mp.find(sum - K) != mp.end())
            {
                len = i - mp[sum - K];
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/sliding-window-maximum/)
{
public:
    vector<int> maxSlidingWindow(int arr[], int n, int k) // Time O(N), Space O(K)
    {
        vector<int> ans;
        multiset<int, greater<int>> mst;

        for (int i = 0; i < n; i++)
        {
            mst.insert(arr[i]);

            if (mst.size() > k)
            {
                mst.erase(mst.find(arr[i - k]));
            }

            if (mst.size() == k)
            {
                ans.push_back(*mst.begin());
            }
        }
        return ans;
    }
};
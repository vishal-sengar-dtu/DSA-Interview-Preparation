#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/kth-largest-element-in-an-array/)
{
public:
    int findKthLargest(int arr[], int n, int k) // Time O(N), Space O(K)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap

        for (int i = 0; i < n; i++)
        {
            if (i < k)
                pq.push(arr[i]);

            else if (pq.top() < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
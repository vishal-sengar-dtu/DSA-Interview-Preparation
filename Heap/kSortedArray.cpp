#include <bits/stdc++.h>
using namespace std;

class Solution // (https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0)
{
public:
    vector<int> kSortedArray(int arr[], int n, int k) // Time O(N), Space O(k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min priority queue of size k;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (i < k)
                pq.push(arr[i]);
            else
            {
                ans.push_back(pq.top());
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans = obj.kSortedArray(arr, n, k);

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
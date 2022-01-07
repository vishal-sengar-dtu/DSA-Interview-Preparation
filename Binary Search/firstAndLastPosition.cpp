#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
{
    bool binarySearch(int arr[], int n, int key)
    {
        int beg = 0, end = n - 1;

        while (beg <= end)
        {
            int mid = beg + (end - beg / 2);

            if (arr[mid] == key)
                return true;

            if (arr[mid] > key)
                end = mid - 1;

            if (arr[mid] < key)
                beg = mid + 1;
        }
        return false;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/search-in-rotated-sorted-array/)
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;

            // first half is sorted OR the array is rotated less than N/2 times (L => R).
            if (nums[lo] <= nums[mid])
            {
                if (target >= nums[lo] && target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            // second half is sorted.
            else
            {
                if (target >= nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        // target is not in the array.
        return -1;
    }
};
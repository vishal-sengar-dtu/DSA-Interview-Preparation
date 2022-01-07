#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
{
    int Occurence(vector<int> &nums, int target, bool type)
    {
        // type : 0 => first occurence
        // type : 1 => last occurence

        int lo = 0, hi = nums.size() - 1;
        int mid, pos = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo / 2);

            if (nums[mid] == target)
            {
                // store the position and keep on searching.
                pos = mid;
                // for last occurence keep on serching the target on the right side. 
                if(type)
                    lo = mid + 1;
                // for first occurence keep on serching the target on the left side. 
                else
                    hi = mid - 1;
            }
            if (nums[mid] > target)
                hi = mid - 1;
            if (nums[mid] < target)
                lo = mid + 1;
        }
        return pos;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) // Non STL solution
    {
        vector<int> ans(2);

        ans[0] = Occurence(nums, target, 0);
        ans[1] = Occurence(nums, target, 1);
    }

    vector<int> searchRange(vector<int> &nums, int target) // STL solution
    {
        vector<int> ans(2);

        if (binary_search(nums.begin(), nums.end(), target))
        {
            // lower_bound return the iterator for the first occurence of the target.
            auto it = lower_bound(nums.begin(), nums.end(), target);
            ans[0] = it - nums.begin();

            // upper_bound return the iterator for the just greater element then the target.
            auto it = upper_bound(nums.begin(), nums.end(), target);
            ans[1] = it - nums.begin() - 1;
        }
        else
        {
            ans[0] = -1;
            ans[1] = -1;
        }
        return ans;
    }
};

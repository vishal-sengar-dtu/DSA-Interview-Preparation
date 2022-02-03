#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int beg = 0, end = numbers.size() - 1;
        vector<int> res{-1, -1};

        while (beg < end)
        {
            int pair_sum = numbers[beg] + numbers[end];

            if (pair_sum > target)
                end--;

            else if (pair_sum < target)
                beg++;

            else
            {
                res[0] = beg + 1;
                res[1] = end + 1;
                break;
            }
        }
        return res;
    }
};
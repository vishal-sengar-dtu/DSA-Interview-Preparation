#include <bits/stdc++.h>
using namespace std;

/*
Company Tags : {Hike, Amazon, MakeMyTrip, Qualcomm, Infosys, Microsoft, Google, Salesforce, Flipkart}
Question Link : {https://leetcode.com/problems/next-permutation/}
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        bool flag = false;

        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                flag = true;
                int pivot = i - 1, idx = i;
                int min_element_greater_than_pivot = nums[idx];

                for (int j = pivot + 1; j < n; j++)
                {
                    if (nums[j] > nums[pivot] && nums[j] <= min_element_greater_than_pivot)
                    {
                        min_element_greater_than_pivot = nums[j];
                        idx = j;
                    }
                }
                swap(nums[pivot], nums[idx]);
                reverse(nums.begin() + pivot + 1, nums.end());
                break;
            }
        }
        if (!flag)
            reverse(nums.begin(), nums.end());
    }
};
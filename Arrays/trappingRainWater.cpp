#include <bits/stdc++.h>
using namespace std;

/*
Company Tags : {Amazon, Microsoft, Google, Flipkart}
Question Link : {https://leetcode.com/problems/trapping-rain-water/}
*/

class Solution
{
public:
    int trap1(vector<int> &height) // Time O(N*N), Space O(1)
    {
        int n = height.size();
        int vol = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int lMax = 0, rMax = 0;

            for (int j = i; j >= 0; j--)
                lMax = max(lMax, height[j]);
            for (int k = i; k < n; k++)
                rMax = max(rMax, height[k]);

            int temp = min(lMax, rMax) - height[i];
            vol += temp;
        }
        return vol;
    }

    int trap2(vector<int> &height) // Time O(N), Space O(N)
    {
        int n = height.size();
        int vol = 0;

        vector<int> lMax(n), rMax(n);

        lMax[0] = height[0];
        rMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
            lMax[i] = max(lMax[i - 1], height[i]);

        for (int i = n - 2; i >= 0; i--)
            rMax[i] = max(rMax[i + 1], height[i]);

        for (int i = 1; i < n - 1; i++)
        {
            int temp = min(lMax[i], rMax[i]) - height[i];
            vol += temp;
        }
        return vol;
    }

    int trap3(vector<int> &height) // Time O(N), Space O(1)
    {
        int i = 0, j = height.size() - 1, vol = 0;
        int lMax = height[i];
        int rMax = height[j];

        while (i <= j)
        {
            lMax = max(lMax, height[i]);
            rMax = max(rMax, height[j]);

            if (lMax <= rMax)
                vol += lMax - height[i++];
                
            else if (lMax >= rMax)
                vol += rMax - height[j--];
        }
        return vol;
    }
};
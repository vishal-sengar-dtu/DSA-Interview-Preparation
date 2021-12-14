#include <bits/stdc++.h>
using namespace std;

class MaxProductSubarray
{
public:
    long long max(long long a, long long b)
    {
        return a >= b ? a : b;
    }

    long long min(long long a, long long b)
    {
        return a <= b ? a : b;
    }

    long long kadane(int arr[], int n)
    {
        long long currMax, currMin, maxProduct, tmp;
        currMax = currMin = 1;
        maxProduct = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            tmp = currMax;

            currMax = max(arr[i], max(currMax * arr[i], currMin * arr[i]));
            currMin = min(arr[i], min(tmp * arr[i], currMin * arr[i]));

            maxProduct = max(maxProduct, currMax);
        }
        return maxProduct;
    }
};
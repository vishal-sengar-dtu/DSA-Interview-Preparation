#include <bits/stdc++.h>
using namespace std;

class Kadane
{
public:
    int maxSumSubarray(int arr[], int n)
    {
        int maxSum = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (maxSum < sum)
                maxSum = sum;
                
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    };

    int maxProductSubarray(int arr[], int n)
    {
    }
};
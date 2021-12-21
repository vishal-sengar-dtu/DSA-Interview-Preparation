#include <bits/stdc++.h>
using namespace std;

class Solution // (https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1#)
{
private:
    int noConsecutiveOne(int n) // Time O(N), Space O(N)
    {
        int zero[n + 1]; // binary strings ending with zero
        int one[n + 1];  // binary strings ending with one *(also no consecutive 1's)

        zero[1] = 1;
        one[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            zero[i] = zero[i - 1] + one[i - 1];
            one[i] = zero[i - 1];
        }
        return zero[n] + one[n]; // all binary strings of size 'n' without consecutive 1's
    }

    int optimizedFunc(int n) // Time O(N), Space O(1)
    {
        int zeros = 1, ones = 1, newZeros, newOnes;

        for (int i = 2; i <= n; i++)
        {
            newZeros = zeros + ones;
            newOnes = zeros;

            zeros = newZeros;
            ones = newOnes;
        }
        return zeros + ones;
    }

public:
    int findIntegers(int num) // (https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
    {
        // precomputing the finonacci series till n = 30
        int fib[31];

        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i <= 30; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        int ans = 0, k = 30;
        bool isPrevBitOne = false; // for checking consecutive 1's in 'num'

        while (k >= 0) // iterating on kth bits
        {
            if (num & (1 << k)) // If kth bit is (1) set
            {
                ans += fib[k];
                if (isPrevBitOne)
                    return ans;
                else
                    isPrevBitOne = true;
            }
            else
            {
                isPrevBitOne = false;
            }
            k--;
        }

        return ans + 1; // adding 1 to ans because the 'num' itself does not contain consecutive 1's
    }
};
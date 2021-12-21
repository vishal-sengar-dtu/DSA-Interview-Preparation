#include <bits/stdc++.h>
using namespace std;

class Fibonacci // (https://leetcode.com/problems/climbing-stairs/)
{
public:
    int climbStairs(int n) // Time O(N), Space O(1)
    {
        int a = 1, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
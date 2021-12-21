#include <bits/stdc++.h>
using namespace std;

class Fibonacci // (https://leetcode.com/problems/fibonacci-number/)
{
public:
    int
    Recursion(int n) // Time O(2^n) Space O(1)
    {
        if (n == 0 || n == 1)
            return n;

        return Recursion(n - 1) + Recursion(n - 2);
    }

    int Memoization(int n, vector<int> &dp) // Time O(N) Space O(N)
    {
        if (n == 0 || n == 1)
            return dp[n] = n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = Memoization(n - 1, dp) + Memoization(n - 2, dp);
    }

    int BottomUp(int n) // Time O(N) Space O(N)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int spaceOptimizedDP(int n) // Time O(N) Space O(1)
    {
        int a = 0;
        int b = 1;
        int c;

        for (int i = 0; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return a;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    Fibonacci obj;
    cout << obj.Recursion(n);
    cout << obj.Memoization(n, dp);
    cout << obj.BottomUp(n);
    cout << obj.spaceOptimizedDP(n);
}
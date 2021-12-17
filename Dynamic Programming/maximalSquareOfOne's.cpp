#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/maximal-square/)
{
public:
    int maximalSquare(vector<vector<char>> &matrix) // Time O(N * M), Space O(N * M)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));

        int sz = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';

                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

                sz = max(sz, dp[i][j]);
            }
        }
        return sz * sz;
    }
};
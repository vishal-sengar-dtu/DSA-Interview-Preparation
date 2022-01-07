#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/number-of-islands/)
{
    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        int R = grid.size(), C = grid[0].size();

        if (i < 0 || j < 0 || i == R || j == C || grid[i][j] == '0')
            return false;
        return true;
    }

    void eraseIsland(vector<vector<char>> &grid, int i, int j)
    {
        int R = grid.size(), C = grid[0].size();

        if (isValid(grid, i, j))
        {
            grid[i][j] = '0';

            eraseIsland(grid, i - 1, j);
            eraseIsland(grid, i, j + 1);
            eraseIsland(grid, i + 1, j);
            eraseIsland(grid, i, j - 1);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) // DFS Approch
    {
        int R = grid.size(), C = grid[0].size();
        int island = 0;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] == '1')
                {
                    island++;
                    eraseIsland(grid, i, j);
                }
            }
        }
        return island;
    }

    int numIslands(vector<vector<char>> &grid) // BFS
    {
        
    }
};
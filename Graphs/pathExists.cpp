#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/find-if-path-exists-in-graph/)
{
public:
    bool dfs1(vector<vector<int>> &adj, vector<bool> &vis, int src, int dest)
    {
        vis[src] = 1;
        if (src == dest)
            return true;

        for (auto it : adj[src])
        {
            if (!vis[it] && dfs1(adj, vis, it, dest))
                return true;
        }
        return false;
    }

    void dfs2(vector<vector<int>> &adj, vector<bool> &vis, int src, int dest)
    {
        vis[src] = true;
        if (src == dest)
            return;

        for (auto it : adj[src])
        {
            if (!vis[it])
                dfs2(adj, vis, it, dest);
        }
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        return dfs1(adjList, visited, source, destination);
        dfs2(adjList, visited, source, destination);
        return visited[destination];
    }
};
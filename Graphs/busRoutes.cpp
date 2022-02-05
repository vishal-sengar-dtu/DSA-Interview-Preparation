#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Winzo}
    Question Link : {https://leetcode.com/problems/bus-routes/}
*/

class Solution
{
private:
    unordered_map<int, vector<int>> bus_from;

public:
    void dfsUtil(int current_bus_stop, int bus_count, int bus_no, int &ans, vector<vector<int>> &routes, int target, unordered_set<int> &visited)
    {
        if (current_bus_stop == target)
        {
            ans = min(ans, bus_count);
            return;
        }

        visited.insert(current_bus_stop);
        auto buses = bus_from[current_bus_stop];

        for (int i = 0; i < buses.size(); i++)
        {
            for (int bus_stop : routes[buses[i]])
            {
                if (visited.find(bus_stop) == visited.end())
                {
                    if (bus_no != buses[i])
                    {
                        bus_count++;
                        bus_no = buses[i];
                    }
                    dfsUtil(bus_stop, bus_count, bus_no, ans, routes, target, visited);
                }
            }
        }
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        int ans = INT_MAX;
        unordered_set<int> visited;

        for (int i = 0; i < routes.size(); i++)
            for (int bus_stop : routes[i])
                bus_from[bus_stop].push_back(i);

        for (auto &buses : bus_from[source])
        {
            dfsUtil(source, 1, buses, ans, routes, target, visited);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
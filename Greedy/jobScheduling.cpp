#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int id;
    int deadline;
    int profit;
};

class Solution
{
public:
    static bool compare(Job a, Job b)
    {
        if (a.deadline == b.deadline)
            return (a.profit > b.profit);
        else
            return (a.deadline < b.deadline);
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);

        int jobCount = 0;
        int maxProfit = 0;
        vector<int> result;

        int temp;
        for (int i = 0; i < n; i++){
            temp = arr[i].deadline;
        }
    }
};

int main()
{
}
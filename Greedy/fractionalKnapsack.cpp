#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int weight;
    int value;
};

class Solution
{
public:
    static bool compare(Item a, Item b)
    {
        double valuePerUnitWeightA = double(a.value) / a.weight;
        double valuePerUnitWeightB = double(b.value) / b.weight;
        return valuePerUnitWeightA > valuePerUnitWeightB;
    }

    double fractionalKnapsack(int W, Item *arr, int n)
    {
        sort(arr, arr + n, compare);

        double totalProfit = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                totalProfit += arr[i].value;
                W -= arr[i].weight;
            }
            else if (W != 0)
            {
                totalProfit += (double(arr[i].value) / arr[i].weight) * W;
                W = 0;
                break;
            }
        }
        return totalProfit;
    }
};

int main()
{
    int n, W;
    cin >> n >> W;

    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;
    cout << obj.fractionalKnapsack(W, arr, n);
}

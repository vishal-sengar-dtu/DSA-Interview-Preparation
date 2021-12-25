#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Only 1 transaction allowed

    int maxProfit(vector<int> &prices) // (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
    {
        int n = prices.size();
        int minBuyingPrice = INT_MAX, mxProfit = 0, dailyProfit;

        for (int i = 0; i < n; i++)
        {
            if (prices[i] < minBuyingPrice)
                minBuyingPrice = prices[i];
            else
            {
                dailyProfit = prices[i] - minBuyingPrice;
                mxProfit = max(mxProfit, dailyProfit);
            }
        }
        return mxProfit;
    }

    // Multiple transactions allowed

    int maxProfit(vector<int> &prices) // (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
    {
        int profit = 0, buyDay = 0, sellDay = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            if (prices[i] >= prices[i - 1])
                sellDay++;
            else
            {
                profit += prices[sellDay] - prices[buyDay];
                buyDay = sellDay = i;
            }
        }
        profit += prices[sellDay] - prices[buyDay];

        return profit;
    }

    // Best Time to Buy and Sell Stock with Cooldown

    int maxProfit(vector<int> &prices, int fee) // (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
    {
    }

    // Best Time to Buy and Sell Stock with Transaction Fee

    int maxProfit(vector<int> &prices, int fee) // (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
    {
    }

    // You may complete at most k transactions. // (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

    int maxProfit(int k, vector<int> &prices)
    {
    }
};
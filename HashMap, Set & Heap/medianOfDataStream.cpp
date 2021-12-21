#include <bits/stdc++.h>
using namespace std;

class MedianFinder // (https://leetcode.com/problems/find-median-from-data-stream/)
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    void addNum(int num)
    {
        if (left.empty() || (left.top() > num))
            left.push(num); // if it belongs to the smaller half
        else
            right.push(num);

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() + 1 < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
            return left.empty() ? 0 : ((left.top() + right.top()) / 2.0);
        else
            return (left.size() > right.size()) ? left.top() : right.top();
    }
};

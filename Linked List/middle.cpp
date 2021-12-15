#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution // (https://leetcode.com/problems/middle-of-the-linked-list/)
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
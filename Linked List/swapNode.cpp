#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution // (https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *ptr1 = head, *ptr2 = head, *kth;

        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        
        while (ptr1->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        swap(kth->val, ptr2->val);
        return head;
    }
};
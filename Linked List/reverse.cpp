#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution // (https://leetcode.com/problems/reverse-linked-list/)
{
    ListNode *recursion(ListNode *node, ListNode *newHead)
    {
        if (node->next == NULL)
        {
            newHead = node;
            return;
        }
        recursion(node->next, newHead);

        //postorder
        node->next->next = node;
        node->next = NULL;
    }

public:
    ListNode *reverseList(ListNode *head) // Iterative Approch
    {
        ListNode *prev, *curr, *next;
        curr = head;
        prev = next = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head = prev;
    }

    ListNode *reverseList(ListNode *head) // Recursive Approch
    {
        return recursion(head, NULL);
    }
};
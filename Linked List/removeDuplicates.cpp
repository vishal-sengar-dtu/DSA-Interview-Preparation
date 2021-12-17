#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

class Solution // (https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (!head)
            return head;

        Node *tmp1 = head, *tmp2 = head->next;

        while (tmp2)
        {
            if (tmp1->val == tmp2->val)
                tmp1->next = tmp2->next;
            else
                tmp1 = tmp1->next;

            tmp2 = tmp2->next;
        }
        return head;
    }
};
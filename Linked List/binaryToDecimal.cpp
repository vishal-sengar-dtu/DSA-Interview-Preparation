#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution // (https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
{
public:
    int getDecimalValue(ListNode *head)
    {
        int decimal = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            decimal *= 2;
            decimal += temp->val;
            temp = temp->next;
        }
        return decimal;
    }
};
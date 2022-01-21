#include <bits/stdc++.h>
using namespace std;

/*
    Question Link : {https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/}
*/

class Solution
{
public:
    int distinctSubstring(string str) // Time O(N * N)
    {
        Node *root = new Node();
        int count = 0;

        for (int i = 0, j = i; i < str.length(); i++)
        {
            Node *node = root;

            for (int j = i; j < str.length(); j++)
            {
                if (!node->containsKey(str[j]))
                {
                    node->put(str[j], new Node());
                    count++;
                }
                node = node->get(str[j]);
            }
        }
        /* 1 is added to count because empty string is also condidered as a distinct substring */
        return count + 1;
    }
};

class Node
{
private:
    Node *links[26];

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
            this->links[i] = NULL;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};
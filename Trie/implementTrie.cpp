#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Accolite, Amazon, D-E-Shaw, Microsoft}
    Question Link : {https://leetcode.com/problems/implement-trie-prefix-tree/}
*/

class TrieNode
{
public:
    TrieNode *children[26];
    bool isLeaf;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isLeaf = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word) // Time O(len)
    {
        int len = word.length();
        TrieNode *tmp = root;

        for (int i = 0; i < len; i++)
        {
            char c = word[i] - 'a';

            if (tmp->children[c] == NULL)
                tmp->children[c] = new TrieNode();
            tmp = tmp->children[c];
        }
        tmp->isLeaf = true;
    }

    bool search(string word) // Time O(len)
    {
        int len = word.length();
        TrieNode *tmp = root;

        for (int i = 0; i < len; i++)
        {
            char c = word[i] - 'a';

            if (tmp->children[c] == NULL)
                return false;
            tmp = tmp->children[c];
        }
        return tmp->isLeaf;
    }

    bool startsWith(string prefix)
    {
        int len = prefix.length();
        TrieNode *tmp = root;

        for (int i = 0; i < len; i++)
        {
            char c = prefix[i] - 'a';

            if (tmp->children[c] == NULL)
                return false;
            tmp = tmp->children[c];
        }
        return true;
    }
};
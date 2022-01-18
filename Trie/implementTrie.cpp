#include <bits/stdc++.h>
using namespace std;

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
    /* Initializing the Data Structure */
    Trie()
    {
        root = new TrieNode();
    }

    /* Inserts a word into the Trie */
    void insert(string word)
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

    /* Returns true if the word is in the Trie */
    bool search(string word)
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

    /* Returns true if the word with given prefix exists in the Trie*/
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
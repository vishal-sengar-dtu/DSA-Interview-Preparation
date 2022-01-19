#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {VMWare, Microsoft, Google}
    Question Link : {https://leetcode.com/problems/longest-word-with-all-prefixes/}
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &arr, int N)
    {
        Trie trie;
        for (auto it : arr)
            trie.insert(it);

        string longest = "";
        for (auto it : arr)
        {
            if (trie.checkIfPrefixExists(it))
            {
                if (it.length() > longest.length())
                    longest = it;

                // To store lexiographically smaller string
                else if (it.length() == longest.length() && it < longest)
                    longest = it;
            }
        }
        return longest;
    }
};

class TrieNode
{
private:
    TrieNode *links[26];
    bool flag;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            this->links[i] = NULL;
        this->flag = false;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }

    bool setFlag(bool ans)
    {
        flag = ans;
    }

    bool getFlag()
    {
        return flag;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new TrieNode());
            node = node->get(word[i]);
        }
        node->setFlag(true);
    }

    bool search(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->getFlag();
    }

    bool checkIfPrefixExists(string &prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

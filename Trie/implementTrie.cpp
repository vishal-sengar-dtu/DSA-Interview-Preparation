#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Accolite, Amazon, D-E-Shaw, Microsoft}
    Question Link : {https://leetcode.com/problems/implement-trie-prefix-tree/}
*/

#include <bits/stdc++.h>
using namespace std;

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
    /* Initializing the Data Structure */
    Trie()
    {
        root = new TrieNode();
    }

    /* Inserts a word into the Trie */
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

    /* Returns true if the word is in the Trie */
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

    /* Returns true if the word with given prefix exists in the Trie*/
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
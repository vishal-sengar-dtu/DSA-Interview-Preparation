#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Accolite, Amazon, D-E-Shaw, Microsoft}
    Question Link : {https://leetcode.com/problems/implement-trie-ii-prefix-tree/}
*/

class TrieNode
{
private:
    TrieNode *links[26];
    int prefixCount, wordCount;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;

        prefixCount = 0, wordCount = 0;
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

    void increaseWordCount()
    {
        wordCount++;
    }

    void increasePrefixCount()
    {
        prefixCount++;
    }

    void decreaseWordCount()
    {
        wordCount--;
    }

    void decreasePrefixCount()
    {
        prefixCount--;
    }

    int getPrefixCount()
    {
        return prefixCount;
    }

    int getWordCount()
    {
        return wordCount;
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

            /* increase prefix count every time that sequence of characters are repeated. */
            node->increasePrefixCount();
        }

        /* increase word count only if the character is end of word. */
        node->increaseWordCount();
    }

    /* Return count of the exact word */
    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getWordCount();
    }

    /* Returns count of words with given prefix */
    int countWordsStartingWith(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getPrefixCount();
    }

    /* Erase word only if it exists. Otherwise it can alter the prefix count of some words. */
    void erase(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->get(word[i]);
            node->decreasePrefixCount();
        }
        node->decreaseWordCount();
    }
};
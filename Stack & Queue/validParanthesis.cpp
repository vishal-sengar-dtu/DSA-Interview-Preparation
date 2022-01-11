#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {Yatra.com}
    Question Link : {https://leetcode.com/problems/valid-parentheses/}
*/

class Solution
{
    unordered_map<char, int> symbols = {{'[', 3}, {'{', 2}, {'(', 1}, {']', -3}, {'}', -2}, {')', -1}};

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto bracket : s)
        {
            if (symbols[bracket] > 0)
                st.push(bracket);
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (symbols[bracket] + symbols[top] != 0)
                    return false;
            }
        }
        return st.empty();
    }
};
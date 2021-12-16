#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // input: str = " the sky   is blue  "
    // output: "blue is the sky"

    string reverseWords(string str) // Time O(N), Space O(N)
    {
        stack<string> st;
        string temp = "";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
                temp += str[i];

            if (temp.length() != 0)
                if (str[i] == ' ' || i == str.length() - 1)
                {
                    st.push(temp);
                    temp = "";
                }
        }

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (st.size() != 0)
                res += ' ';
        }

        return res;
    }

    // METHOD-2 (In-Place)
    // reverse individual words ignoring extra spaces, and then reverse the whole string.

    string reverseWords(string str) // Time O(N), Space O(1)
    {
    }
};
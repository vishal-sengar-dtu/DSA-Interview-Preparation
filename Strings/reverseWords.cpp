#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/reverse-words-in-a-string/)
{
    string reverseWordsII(string str) // Time O(N), Space O(1)
    {
        int first = 0, last = 0;

        while (last < str.length())
        {
            if (str[last] == ' ')
            {
                reverse(str.begin() + first, str.begin() + last);
                first = last + 1;
            }
            if (last == str.length() - 1)
                reverse(str.begin() + first, str.end());

            last++;
        }
        return str;
    }

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
        // remove excess spaces
        while (str[0] == ' ')
            str.erase(str.begin());

        while (str[str.length() - 1] == ' ')
            str.erase(str.begin() + str.length() - 1);

        int idx = 0;
        while (idx < str.length())
        {
            if (str[idx] == ' ' && str[idx + 1] == ' ')
                str.erase(str.begin() + idx);
            else
                idx++;
        }

        reverse(str.begin(), str.end());

        return reverseWordsII(str);
    }
};
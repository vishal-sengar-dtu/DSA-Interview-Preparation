#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/reverse-words-in-a-string-iii/)
{
public:
    // input: str = "the sky is blue"
    // output: "eht yks si eulb"

    string reverseWords(string str) // Time O(N), Space O(1)
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
};
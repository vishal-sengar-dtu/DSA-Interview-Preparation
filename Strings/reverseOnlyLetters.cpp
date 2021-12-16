#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // input: str = "Test1ng-Leet=code-Q!"
    // output: "Qedo1ct-eeLg=ntse-T!"

    string reverseOnlyLetters(string str) // Time O(N), Space O(1)
    {
        int first = 0, last = str.length() - 1;

        while (first < last)
        {
            if(isalpha(str[first]) && isalpha(str[last])){
                char tmp = str[last];
                str[last--] = str[first];
                str[first++] = tmp;
            }
            if (!isalpha(str[first]))
                first++;
            if (!isalpha(str[last]))
                last--;       
        }
        return str;
    }
};
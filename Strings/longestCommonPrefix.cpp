#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : {VMWare, Microsoft, Google}
    Question Link : {https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1#}
*/

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N) // Time O(N * max(|arr[i]|)), Space O(max(|arr[i]|))
    {
        if (N != 0)
        {
            string ans = arr[0];
            for (int i = 1; i < N; i++)
            {
                int j = 0;
                string tmp = "";

                while (ans[j] == arr[i][j] && j < ans.length() && j < arr[i].length())
                    tmp += ans[j++];

                ans = tmp;
            }
            return ans.length() == 0 ? "-1" : ans;
        }
        return "-1";
    }
};
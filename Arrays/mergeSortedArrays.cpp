#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags : { Goldman Sachs, Linkedin, Microsoft, Synopsys, Zoho, Adobe }
    Question Link : { https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1 }
*/
class Solution
{
private:
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }

public:
    /* In-place merging */
    void merge(int arr1[], int arr2[], int n, int m) // Time O(M * N), Space O(1)
    {
        int i = 0, j = 0;

        while (i < n)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
                sort(arr2, arr2 + m);
            }
            i++;
        }
    }

    /* Most Optimal Solution - Gap Method */
    void merge(int arr1[], int arr2[], int n, int m) // Time O(N*log(N)), Space O(1) here N = m + n.
    {
        int i, j, gap = m + n;

        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);

            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);

            if (j < m)
            {
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }
};

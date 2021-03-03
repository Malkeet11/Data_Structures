/************************************************************************************************************************************************

Maximum_Sum_No_Adjacent_Elements.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be
adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

Examples :

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int max_sum(int a[], int n)
{
    int excl = 0, incl = a[0];
    for(int i = 1; i < n; i++)
    {
        int temp = excl;
        excl = max(incl, excl);
        incl = temp + a[i];
    }
    return max(incl, excl);
}

int main()
{
    int cap = 6;
    int a[cap] = {5, 5, 10, 100, 10, 5};
    cout << max_sum(a, cap);
    return 0;
}

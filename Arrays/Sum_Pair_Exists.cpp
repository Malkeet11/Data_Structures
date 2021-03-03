/************************************************************************************************************************************************

Sum_Pairs_Exist.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Write a program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x.

Examples:

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists.

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// Method 1
// O(N^2) Time Complexity
// O(2) Space Complexity
void pair_exist(int a[], int n, int s)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] + a[j] == s)
                cout << a[i] << " " << a[j] << "\n";
        }
    }
}

// Method 2
// O(N) Time Complexity
// O(N) Space Complexity
void pair_exist_2(int a[], int n, int s)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        if(mp.find(s - a[i]) != mp.end())
            cout << s - a[i] << " " << a[i] << "\n";
        mp[a[i]]++;
    }
}

int main()
{
    int cap = 6;
    int a[cap] = {1, 2, 3, 4, 5};
    pair_exist_2(a, cap, 6);
    return 0;
}

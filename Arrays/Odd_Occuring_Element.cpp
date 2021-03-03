/************************************************************************************************************************************************

Odd_Occuring_Element.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Given an array of positive integers. All numbers occur even number of times except one number which occurs odd number of times.
Find the number in O(n) time & constant space.
Examples :

Input : arr = {1, 2, 3, 2, 3, 1, 3}
Output : 3

Input : arr = {5, 7, 2, 7, 5, 2, 5}
Output : 5

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N^2) Time Complexity
// O(3) Space
int odd_occuring_1(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int co = 0;
        for(int j = 0; j < n ;j++)
        {
            if(a[j] == a[i])
                co++;
        }
        if(co & 1)
            return a[i];
    }
    return -1;
}

// O(N) Time Complexity
// O(N) Space
int odd_occuring_2(int a[], int n)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]]++;

    for(auto i : mp)
    {
        if(i.second & 1)
            return i.first;
    }
    return -1;
}

// O(N) Time Complexity
// O(1) Space
int odd_occuring_3(int a[], int n)
{
    int xo = 0;
    for(int i = 0; i < n; i++)
        xo ^= a[i];
    return xo;
}

int main()
{
    int cap = 9;
    int a[cap] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << odd_occuring_1(a, cap) << "\n";
    cout << odd_occuring_2(a, cap) << "\n";
    cout << odd_occuring_3(a, cap) << "\n";
    return 0;
}

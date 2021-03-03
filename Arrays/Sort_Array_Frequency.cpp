/************************************************************************************************************************************************

Sort_Array_Frequency.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.

Examples:

Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if(p2.second.second == p1.second.second)
        return (p1.second.first < p2.second.first);
    else
        return (p1.second.second > p2.second.second);
}

void sort_array(int *a, int n)
{
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < n; i++)
    {
        if(mp.find(a[i]) != mp.end())
            mp[a[i]].second++;
        else
            mp[a[i]] = make_pair(i, 1);
    }
    vector<pair<int, pair<int, int>>> v;
    for(auto i : mp)
        v.push_back(make_pair(i.first, i.second));
    sort(v.begin(), v.end(), compare);
    int st = 0;
    for(auto i : v)
    {
        int c = i.second.second;
        while(c--){
            //cout << i.first << " ";
            a[st++] = i.first;
        }
    }
}

int main()
{
    int cap = 8;
    int a[cap] = {2, 5, 2, 8, 5, 6, 8, 8};
    sort_array(a, cap);
    for(int i = 0; i < cap; i++)
        cout << a[i] << " ";
    return 0;
}

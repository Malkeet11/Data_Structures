/*****************************************************************************************************************************************

Stack_Next_Greater_Element.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in the array.
Elements for which no greater element exist, consider next greater element as -1.

Examples:

For an array, the rightmost element always has the next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.
For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N*N) Time
void nge_1(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int ng = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] > a[i])
            {
                ng = a[j];
                break;
            }
        }
        cout << a[i] << " -> " << ng <<"\n";
    }
}

// O(N) Time and O(1) Space
void nge_stack(int a[], int n)
{
    stack<int> s;
    s.push(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(s.empty())
        {
            s.push(a[i]);
            continue;
        }
        while(!s.empty() && a[i] > s.top())
        {
            cout << s.top() << " -> " << a[i] << "\n";
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty())
    {
        cout << s.top() << " -> -1\n";
        s.pop();
    }
}

// O(N) Time and O(N) Space
void nge_stack_2(int a[], int n)
{
    stack<int> s;
    unordered_map<int, int> mp;
    s.push(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(s.empty())
        {
            s.push(a[i]);
            continue;
        }
        while(!s.empty() && a[i] > s.top())
        {
            //cout << s.top() << " -> " << a[i] << "\n";
            mp[s.top()] = a[i];
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty())
    {
        //cout << s.top() << " -> -1\n";
        mp[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < n ; i++)
        cout << a[i] << " -> " << mp[a[i]] << "\n";
}

int main()
{
    int n = 4;
    int a[n] = {4, 5, 2, 25};
    nge_1(a, n);
    nge_stack(a, n);
    nge_stack_2(a, n);
    return 0;
}

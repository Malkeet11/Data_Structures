/************************************************************************************************************************************************

Leaders_In_Array.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// Method 1
// O(N^2) Time Complexity
vector<int> leaders(int a[], int n)
{
    vector<int> ans;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        flag  = 0;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] > a[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            ans.push_back(a[i]);
    }
    return ans;
}

// Method 2
// O(N) Time Complexity
vector<int> leaders_2(int a[], int n)
{
    vector<int> ans;
    if(n == 0)
        return ans;
    ans.push_back(a[n-1]);
    int max_el = a[n-1];
    int i = n-2;
    while(i >= 0)
    {
        if(a[i] > max_el)
        {
            max_el = a[i];
            ans.push_back(a[i]);
        }
        i--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int cap = 6;
    int a[cap] = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders_2(a, cap);
    for(auto i : ans)
        cout << i << " ";
    return 0;
}

/************************************************************************************************************************************************

Majority_Element.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”.
A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

Examples :

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater
than the half of the size of the array size.

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is
greater than the half of the size of the array size.

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// Method 1
// O(N^2) Time Complexity
// O(4) Space Complexity
void majority_element_1(int a[], int n)
{
    int c, f = 0;
    for(int i = 0; i < n; i++)
    {
        c = 1;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] == a[i])
                c++;
        }
        if(c > n/2){
            cout << a[i] << "\n";
            f = 1;
        }
    }
    if(f == 0)
        cout << "No Majority Element\n";
}

// Method 2
// O(N) Time Complexity
// O(N) Space Complexity
void majority_element_2(int a[], int n)
{
    unordered_map<int, int> mp;
    int f = 0;
    for(int i = 0; i < n; i++)
        mp[a[i]]++;
    for(auto i : mp)
    {
        if(i.second > n/2){
            cout << i.first << "\n";
            f = 1;
        }
    }
    if(f == 0)
        cout << "No Majority Element\n";
}

// Method 3 - Using Moore’s Voting Algorithm
// O(N) Time Complexity
// O(1) Space Complexity
/********************************************************************************************************************

The first step gives the element that maybe the majority element in the array.
If there is a majority element in an array, then this step will definitely return majority element,
otherwise, it will return candidate for majority element.

Check if the element obtained from the above step is majority element.
This step is necessary as there might be no majority element.

********************************************************************************************************************/
void majority_element_moore(int a[], int n)
{
    // Finding Maximum occuring Element
    int maj_idx = 0, co = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[maj_idx] == a[i])
            co++;
        else
            co--;
        if(!co)
        {
            maj_idx = i;
            co = 1;
        }
    }

    // Checking if it satisfies Majority element condition
    co = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[maj_idx] == a[i])
            co++;
    }
    if(co > n/2)
    {
        cout << a[maj_idx] <<"\n";
    }
    else
    {
        cout << "No Majority Element\n";
    }
}

int main()
{
    int cap = 9;
    int a[cap] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    majority_element_1(a, cap);
    majority_element_2(a, cap);
    majority_element_moore(a, cap);
    return 0;
}

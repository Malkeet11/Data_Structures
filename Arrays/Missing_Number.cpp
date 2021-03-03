/************************************************************************************************************************************************

Missing_Number.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list.
One of the integers is missing in the list. Write an efficient code to find the missing integer.
Example:

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
Explanation: The missing number from 1 to 5 is 4

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N^2) Time Complexity
// O(3) Space
int missing_number_1(int a[], int n)
{
    for(int i = 1; i <= n+1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
            return i;
    }
    return -1;
}

// O(n) Time Complexity
// O(3) Space

int missing_number_2(int a[], int n)
{
    int s = ((n+1)*(n+2))/2;
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];

    return s-sum;
}

// O(n log(n)) Time Complexity
// O(3) Space
int missing_number_3(int a[], int n)
{
    sort(a, a+n);
    for(int i = 1; i <= n+1; i++)
        if(a[i-1] != i)
            return i;
    return -1;
}

// O(n) Time Complexity
// O(n) Space
int missing_number_4(int a[], int n)
{
    int b[n+2] = {0};
    for(int i = 0; i < n; i++)
        b[a[i]] = -1;

    for(int i = 1; i <= n+1; i++)
        if(b[i] != -1)
            return i;
    return -1;
}

// O(n) Time Complexity
// O(1) Space
int missing_number_5(int a[], int n)
{
    int xo1 = 0, xo2 = 0;
    for(int i = 0; i < n; i++)
        xo1 ^= a[i];

    for(int i = 1; i <= n+1; i++)
        xo2 ^= i;

    return xo1^xo2;
}

int main()
{
    int cap = 7;
    int a[cap] = {1, 2, 4, 6, 3, 7, 8};
    cout << missing_number_1(a, cap) << "\n";
    cout << missing_number_2(a, cap) << "\n";
    cout << missing_number_3(a, cap) << "\n";
    cout << missing_number_4(a, cap) << "\n";
    cout << missing_number_5(a, cap) << "\n";
    return 0;
}

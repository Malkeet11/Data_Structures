/************************************************************************************************************************************************

Count_Inversion.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

nversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0.
If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Example:

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2)

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N*N) Time Complexity
int count_inverse_1(int a[], int n)
{
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[i])
                c++;
        }
    }
    return c;
}

// O() Time Complexity
int count_inverse_2(int a[], int n)
{
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[i])
                c++;
        }
    }
    return c;
}


int main()
{
    int cap = 4;
    int a[cap] = {8, 4, 1, 2};
    cout << count_inverse_1(a, cap) << "\n";
    return 0;
}

/************************************************************************************************************************************************

Reverse_Array.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Reverse an Array.

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void reverse_array_indexes(int *a, int left, int right)
{
    while(left < right)
    {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

// Inbuilt STL algo
void reverse_array_indexes_stl(int *a, int left, int right)
{
    reverse(a+left, a+right+1);
}
int main()
{
    int cap = 10;
    // User Input
    //cin >> n;
    int a[cap] = {1, 2, 3, 4};
    /*for(int i = 0; i < n; i++)
        cin >> a[i];*/
    int n = 4;
    reverse_array_indexes_stl(a, 0, n-1);
    for(int i = 0; i < n ;i++)
        cout << a[i] << " ";
    return 0;
}

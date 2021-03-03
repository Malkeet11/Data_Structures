/************************************************************************************************************************************************

Left_Rotate_Array.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void left_array_rotate_stl(int *a, int n, int d)
{
    d %= n;
    rotate(a, a+d, a+n);
}

// O(N * d) Time Complexity
void left_array_rotate_1(int *a, int n, int d)
{
    d %= n;
    while(d--)
    {
        int temp = a[0];
        for(int i = 0; i < n; i++)
            a[i] = a[i+1];
        a[n-1] = temp;
    }
}

// O(N) Time Complexity
// Juggler's Algorithm
void left_array_rotate_2(int *a, int n, int d)
{
    d %= n;
    int gcd = __gcd(n, d);
    for(int i = 0; i < gcd; i++)
    {
        int temp = a[i];
        int j = i;
        while(1)
        {
            int k = j + d;
            if(k >= n)
                k -= n;
            if(k == i)
                break;

            a[j] = a[k];
            j = k;
        }
        a[j] = temp;
    }
}

// O(N) Time
// Reversal Algorithm
void reverse_array(int *a, int l, int r)
{
    while(l < r)
        swap(a[l++], a[r--]);
}
void left_array_rotate_3(int *a, int n, int d)
{
    d %= n;
    reverse_array(a, 0, d-1);
    reverse_array(a, d, n-1);
    reverse_array(a, 0, n-1);
}

int main()
{
    int cap = 7;
    int a[cap] = {1, 2, 3, 4, 5, 6, 7};
    //left_array_rotate_stl(a, cap, 2);
    //left_array_rotate_1(a, cap, 2);
    //left_array_rotate_2(a, cap, 2);
    left_array_rotate_3(a, cap, 2);
    for(int i = 0; i < cap; i++)
        cout << a[i] << " ";
    return 0;
}

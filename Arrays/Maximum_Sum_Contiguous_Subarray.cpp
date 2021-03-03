/************************************************************************************************************************************************

Maximum_Sub_Contiguous_Subarray.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
Example : {-2, -3, 4, -1, -2, 1, 5, -3}
Output : 7

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N) Time Complexity
// Kadane's Algorithm
int max_sum_1(int a[], int n)
{
    int cur_max = a[0], max_so_far = a[0];
    for(int i = 1; i < n; i++)
    {
        cur_max = max(cur_max + a[i], a[i]);
        max_so_far = max(cur_max, max_so_far);
    }
    return max_so_far;
}

int main()
{
    int cap = 8;
    int a[cap] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << max_sum_1(a, cap) << "\n";
    return 0;
}

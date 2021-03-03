/************************************************************************************************************************************************

Maximum_Product_Contiguous_Subarray.cpp
Created on: 02-Mar-2021
Author: Malkeet Mehra

Write an efficient program to find the product of contiguous subarray within a one-dimensional array of numbers which has the largest product.
Example : {6, -3, -10, 0, 2}
Output : 180

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// O(N*N) Time
// Brute Force
int max_prod_1(int a[], int n)
{
    int prod = 1;
    for(int i = 0; i < n; i++)
    {
        int loc_prod = a[i];
        for(int j = i+1; j < n; j++)
        {
            prod = max(prod, loc_prod);
            loc_prod *= a[j];
        }
        prod = max(prod, loc_prod);
    }
    return prod;
}

int main()
{
    int cap = 5;
    int a[cap] = {6, -3, -10, 0, 2};
    cout << max_prod_1(a, cap) << "\n";
    return 0;
}

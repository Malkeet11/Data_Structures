/************************************************************************************************************************************************

Search_Insert_Delete_Sorted_Array.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Search, insert and delete in a Sorted array

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int search_element(int a[], int n, int k)
{
    int l = 0, r = n-1, mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] == k)
            return mid+1;
        else if(a[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int insert_element(int *a, int n, int cap, int k)
{
    if(n >= cap)
        return n;
    int i = n-1;
    while(i >= 0 && a[i] > k){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = k;
    return n+1;
}

int delete_element(int *a, int n, int k)
{
    int loc = -1;
    if(n == 0)
        return n;
    int i = search_element(a, n, k);
    if(i == -1)
        return n;
    i--;
    while(i < n)
    {
        a[i] = a[i+1];
        i++;
    }
    return n-1;
}

int main()
{
    int cap = 10;
    // User Input
    //cin >> n;
    int a[cap] = {1, 2, 4, 5};
    /*for(int i = 0; i < n; i++)
        cin >> a[i];*/
    int k = 5;
    int n = 4;
    cout << search_element(a, n, 2)<< "\n";

    n = insert_element(a, n, cap, 3);
    for(int i = 0; i < n ;i++)
        cout << a[i] << " ";

    cout << "\n";

    n = delete_element(a, n, 6);
    for(int i = 0; i < n ;i++)
        cout << a[i] << " ";
    return 0;
}

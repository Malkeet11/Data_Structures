/************************************************************************************************************************************************

Search_Insert_Delete_Unsorted_Array.cpp
Created on: 01-Mar-2021
Author: Malkeet Mehra

Search, insert and delete in an unsorted array

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int search_element(int a[], int n, int k)
{
    for(int i = 0; i < n; i++)
        if(a[i] == k)
            return i+1;
    return -1;
}

int insert_end_array(int *a, int n, int k)
{
    a[n] = k;
    return n+1;
}

int delete_element(int *a, int n, int k)
{
    int loc = -1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == k)
        {
            loc = i;
            break;
        }
    }
    if(loc == -1)
        return n;
    for(int i = loc; i < n; i++)
        a[i] = a[i+1];
    return n-1;
}

int main()
{
    int n = 10;
    // User Input
    //cin >> n;
    int a[n] = {2, 4, 1, 5, 3};
    /*for(int i = 0; i < n; i++)
        cin >> a[i];*/
    int k = 5;
    cout << search_element(a, n, k)<< "\n";

    int cap = 5;
    cap = insert_end_array(a, cap, 10);
    for(int i = 0; i < cap ;i++)
        cout << a[i] << " ";

    cout << "\n";

    cap = delete_element(a, cap, 2);
    for(int i = 0; i < cap ;i++)
        cout << a[i] << " ";
    return 0;
}

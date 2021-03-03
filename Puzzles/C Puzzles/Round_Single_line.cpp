/*********************************************************************************************************************************************

Round_Single_line.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a one line C function to round floating point numbers

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int roundfloat(float n)
{
    return n < 0 ? n - 0.5 : n + 0.5;
}
int main()
{
    float n;
    cin >> n;
    cout << roundfloat(n);
    return 0;
}

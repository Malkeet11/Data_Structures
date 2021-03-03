/*********************************************************************************************************************************************

Sum_digits_single_line.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Given a number, find sum of its digits in single line.

Examples :

Input : n = 687
Output : 21

Input : n = 12
Output : 3

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int sum_digit(int n)
{
    return (n > 0) ? (n%10) + sum_digit(n/10) : 0;
}

int main()
{
    int n = 12345;
    cout << sum_digit(n);
    return 0;
}

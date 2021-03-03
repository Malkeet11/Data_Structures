/*********************************************************************************************************************************************

Sum_two_numbers_without_any_operator.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a program to find sum of positive integers without using any operator. Only use of printf() is allowed.
No other library function can be used.

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int sum_two(int a, int b)
{
    return printf("%*c%*c", a, '\r', b, '\r');
}

int main()
{
    int a = 5, b = 10;
    printf("%d", sum_two(a, b));
    return 0;
}

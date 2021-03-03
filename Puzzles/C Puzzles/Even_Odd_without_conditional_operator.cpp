/*********************************************************************************************************************************************

Condition_Printf.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a C/C++ program that accepts a number from the user and prints “Even” if the entered number is even
and prints “Odd” if the number is odd.
You are not allowed to use any comparison (==, <,>,…etc) or conditional  statements (if, else, switch, ternary operator,. Etc).

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;
    ((n & 1) && cout << "Odd") || cout << "Even";
    return 0;
}

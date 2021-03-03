/*********************************************************************************************************************************************

Print_Numbers_without_semicolon.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

How to print numbers from 1 to N without using any loop in C.

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    if(n <= 0)
        return;
    print(n-1);
    printf("%d ", n);
}

int main()
{
    int n = 10;
    print(n);
    return 0;
}

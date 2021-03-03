/*********************************************************************************************************************************************

Condition_Printf.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

What is the best way in C to convert a number to a string and vice-versa?

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Number to String
    float n = 10.11f;
    char s[100];
    sprintf(s, "%f", n);
    puts(s);

    // String to Number
    float x;
    sscanf(s, "%f", &x);
    printf("%f", x);
    return 0;
}


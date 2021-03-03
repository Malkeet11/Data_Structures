/*********************************************************************************************************************************************

Print_without_semicolon.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a C program to print “Geeks for Geeks” without using a semicolon

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    if(!(cout << "Geeks\n")){}
    // Or
    while(!(cout << "Geeks")){}
    return 0;
}

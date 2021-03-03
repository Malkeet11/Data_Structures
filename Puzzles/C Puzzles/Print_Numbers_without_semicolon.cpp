/*********************************************************************************************************************************************

Print_Numbers_without_semicolon.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

How to print numbers from 1 to N without using any semicolon in C.


#include<stdio.h>
#define N 100

// Add your code here to print numbers from 1
// to N without using any semicolon
What code to add in above snippet such that it doesn’t contain semicolon and prints numbers from 1 to N?

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define n 10
/*
void print(int n)
{
    int i = 1;
    while(printf("%d",i) && (++i) <= n)
    {

    }
}*/
int main(int i)
{
    while(printf("%d", i) && (++i <= n))
    {

    }
}

/*********************************************************************************************************************************************

Print_Number_Own_print.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a C function print(n) that takes a long int number n as argument, and prints it on console.
The only allowed library function is putchar(), no other function like itoa() or printf() is allowed. Use of loops is also not allowed.

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void print(ll n)
{
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if(n == 0)
        return;
    print(n/10);
    putchar(n % 10 + '0');
}

int main()
{
    ll n;
    cin >> n;
    print(n);
    return 0;
}

/*********************************************************************************************************************************************

Implement_Itoa_function.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Itoa function converts integer into null-terminated string.
It can convert negative numbers too. The standard definition of itoa function is give below:-
char* itoa(int num, char* buffer, int base)
{
}
The third parameter base specify the conversion base.
For example:- if base is 2, then it will convert the integer into its binary compatible string or if base is 16,
then it will create hexadecimal converted string form of integer number.

If base is 10 and value is negative, the resulting string is preceded with a minus sign (-).
With any other base, value is always considered unsigned.

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
void reverse_str(char *s, int l, int r)
{
    while(l < r)
    {
        char x = s[l];
        s[l] = s[r];
        s[r] = x;
        l++;
        r--;
    }
}
char* convert_to_str(int n, char *buffer, int b)
{
    int i = 0, neg_flag = 0;
    if(n == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }
    if(n < 0)
    {
        neg_flag = 1;
        n = -n;
    }
    while(n)
    {
        int rem = n % b;
        buffer[i++] = rem > 9 ? (rem-10) + 'A' : rem + '0';
        n /= b;
    }
    if(neg_flag)
        buffer[i++] = '-';
    buffer[i] = '\0';
    reverse_str(buffer, 0, i-1);
    return buffer;
}

int main()
{
    int n = 1234;
    int base = 16;
    char buffer[100];
    cout << convert_to_str(n, buffer, base);
    return 0;
}

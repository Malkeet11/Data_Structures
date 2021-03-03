/*********************************************************************************************************************************************

Convert_Float_to_String.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a C function ftoa() that converts a given floating-point number or a double to a string.
Use of standard library functions for direct conversion is not allowed. The following is prototype of ftoa().
The article provides insight of conversion of C double to string.

ftoa(n, res, afterpoint)
n          --> Input Number
res[]      --> Array where output string to be stored
afterpoint --> Number of digits to be considered after the point.
Example:

ftoa(1.555, str, 2) should store “1.55” in res.
ftoa(1.555, str, 0) should store “1” in res..

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

char* ftostr(int n, char *res, int point)
{

}

int main()
{
    float n = 12.2342;
    cin >> n;
    print(n);
    return 0;
}

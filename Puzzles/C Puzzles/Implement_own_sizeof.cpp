/*********************************************************************************************************************************************

Own_sizeof.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Implement Your Own sizeof

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define sizeofvar(x) (char *)(&x+1) - (char *)(&x)
int main()
{
    float n;
    cout << sizeofvar(n);
    return 0;
}

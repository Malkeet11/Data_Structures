/*********************************************************************************************************************************************

Count_set_bits.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Count set bits of a number.

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

// Log(N)
int count_set_1(int n)
{
    int c = 0;
    while(n)
    {
        n &= (n-1);
        c++;
    }
    return c;
}

// Log(N)
int count_set_1_rec(int n)
{
    return n > 0 ? 1 + count_set_1_rec(n&(n-1)) : 0;
}

// Log(N)
int count_set_2(int n)
{
    int c = 0;
    while(n){
        c += (n & 1);
        n >>= 1;
    }
    return c;
}

// Log(N)
int count_set_2_rec(int n)
{
    return (n > 0) ? (n & 1) + count_set_2_rec(n >> 1) : 0;
}

// STL
int count_set_3(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    int n;
    cin >> n;
    cout << count_set_1(n) << "\n";
    cout << count_set_1_rec(n) << "\n";
    cout << count_set_2(n) << "\n";
    cout << count_set_2_rec(n) << "\n";
    cout << count_set_3(n) << "\n";
    return 0;
}

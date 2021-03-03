/*********************************************************************************************************************************************

Change_Replace_Character.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

In the below code, change/add only one character and print ‘*’ exactly 20 times.


int main()
{
    int i, n = 20;
    for (i = 0; i < n; i--)
        printf("*");
    getchar();
    return 0;
}

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{

    int i, n = 20;
    // Solution 1 Replacing decrement operator
    for (i = 0; i < n; n--)
        printf("*");
    cout << "\n";
    n = 20;


    // Solution 2 Changing conditional operator
    for (i = 0; -i < n; n--)
        printf("*");
    n = 20;
    cout << "\n";


    // Solution 3 Changing conditional operator to negate(1s complement(Print 21 times)
    /******************************************************************
        No.                     One's complement
         0 (00000..00)            -1 (1111..11)
        -1 (11..1111)             0 (00..0000)
        -2 (11..1110)             1 (00..0001)
        -3 (11..1101)             2 (00..0010)
        ...............................................
        -20 (11..01100)           19 (00..10011)


    *******************************************************************/
    for (i = 0; ~i < n; n--)
        printf("*");
    return 0;
}

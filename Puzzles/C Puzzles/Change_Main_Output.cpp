/*********************************************************************************************************************************************

Change_main_Output.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Consider the following program. Change the program so that the output of printf is always 10. It is not allowed to change main().
Only fun() can be changed.

void fun()
{
    // Add something here so that the printf in main prints 10
}

int main()
{
    int i = 10;
    fun();
    i = 20;
    printf("%d", i);
    return 0;
}

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
void fun()
{
    // Add something here so that the printf in main prints 10
    #define printf(x, y) printf(x, 10)
}

int main()
{
    int i = 10;
    fun();
    i = 20;
    printf("%d", i);
    return 0;
}

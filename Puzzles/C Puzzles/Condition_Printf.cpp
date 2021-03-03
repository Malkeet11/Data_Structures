/*********************************************************************************************************************************************

Condition_Printf.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

What should be the “condition” so that the following code snippet prints both HelloWorld

      if  "condition"
          printf ("Hello");
      else
          printf("World");

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    if(!printf("Hello"))
        printf ("Hello");
    else
        printf("World");

    /*if(fork())
        printf ("Hello");
    else
        printf("World");*/
    return 0;
}

/*********************************************************************************************************************************************

Log_in_one_line.cpp
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

int cal_log10(int n)
{
    return (n > 9) ?(1+cal_log(n/10)):0;
}

int cal_logx(int n, int x)
{
    return n > x-1 ? (1+cal_logx(n/x, x)):0;
}
int main()
{
    // Calculates Log 10;
    cout << cal_log10(115) << "\n";
    cout << cal_logx(33, 2);
    return 0;
}

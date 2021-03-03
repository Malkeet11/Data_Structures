/*********************************************************************************************************************************************

Calculate_String_Size.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Find the length of a string without using any loops and string.h in C. Your program is supposed to behave in following way:

Enter a string: GeeksforGeeks (Say user enters GeeksforGeeks)
Entered string is: GeeksforGeeks
Length is: 13

**********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int size_string(char x[], int n)
{
    return x[n] ? 1 + size_string(x, n + 1) : 0;
}

void size_string_2(char x[])
{
    cout << "Entered string is: ";
    int len = (printf("%s", x));
    cout << "\nLength is: " << len <<"\n";
}

int main()
{
    char x[100] = "afsfsgf";
    //getline(cin, x);
    cout << "Entered string is: " << x << "\nLength is: " << size_string(x, 0) <<"\n";

    size_string_2(x);
    return 0;
}

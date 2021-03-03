/*****************************************************************************************************************************************

Stack_String_Reversal.cpp
Created on: 28-Feb-2021
Author: Malkeet Mehra

Given a string, reverse it using stack. For example “GeeksQuiz” should be converted to “ziuQskeeG”.

Following is simple algorithm to reverse a string using stack.

1) Create an empty stack.
2) One by one push all characters of string to stack.
3) One by one pop all characters from stack and put
   them back to string.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void string_reversal(string& str)
{
    stack <int> s;
    int i = 0;
    while(str[i])
    {
        s.push(str[i]);
        i++;
    }
    i = 0;
    while(!s.empty())
    {
        str[i] = s.top();
        s.pop();
        i++;
    }
}

int main()
{
    string str;
    getline(cin, str);
    string_reversal(str);
    cout << str;
    return 0;
}

/************************************************************************************************************************************************

Stack_Check_Balanced_Paranthesis.cpp
Created on: 28-Feb-2021
Author: Malkeet Mehra

Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced

Input: exp = “[(])”
Output: Not Balanced

*************************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool check_expression(string str)
{
    stack <int> s;
    int i = 0;
    while(str[i])
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i++]);
            continue;
        }
        if(s.empty())
            return false;
        if(str[i] == ')')
        {
            char x = s.top();
            s.pop();
            if(x != '(')
                return false;
        }
        else if(str[i] == '}')
        {
            char x = s.top();
            s.pop();
            if(x != '{')
                return false;
        }
        else if(str[i] == ']')
        {
            char x = s.top();
            s.pop();
            if(x != '[')
                return false;
        }
        i++;
    }
    return s.empty();
}

int main()
{
    string exp;
    getline(cin, exp);
    cout << check_expression(exp);
    return 0;
}

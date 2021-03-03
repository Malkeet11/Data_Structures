/*****************************************************************************************************************************************

Stack_Reverse_Recursion.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc,
and you can only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void insert_at_end(int x)
{
    if(s.empty())
        s.push(x);
    else
    {
        int t = s.top();
        s.pop();
        insert_at_end(x);

        s.push(t);
    }
}

void reverse_stack()
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        reverse_stack();

        insert_at_end(x);
    }
}


int main()
{
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse_stack();
    string x = "";
    while(!s.empty())
    {
        //cout << s.top();
        x += char(s.top()+'0');
        s.pop();
    }
    cout << x;
    return 0;
}

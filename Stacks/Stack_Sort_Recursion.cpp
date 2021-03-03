/*****************************************************************************************************************************************

Stack_Sort_Recursion.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Given a stack, sort it using recursion. Use of any loop constructs like while, for..etc is not allowed.
We can only use the following ADT functions on Stack S:

is_empty(S)  : Tests whether stack is empty or not.
push(S)         : Adds new element to the stack.
pop(S)         : Removes top element from the stack.
top(S)         : Returns value of the top element. Note that this
               function does not remove element from the stack.
Example:

Input:  -3  <--- Top
        14
        18
        -5
        30

Output: 30  <--- Top
        18
        14
        -3
        -5

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void insert_at_sorted_pos(int x)
{
    if(s.empty() || s.top() < x)
        s.push(x);
    else
    {
        int t = s.top();
        s.pop();
        insert_at_sorted_pos(x);

        s.push(t);
    }
}

void sort_stack()
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        sort_stack();

        insert_at_sorted_pos(x);
    }
}


int main()
{
    s.push(4);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(3);

    sort_stack();
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

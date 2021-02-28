/*****************************************************************************************************************************************

Stack_using_Array.cpp
Created on: 27-Feb-2021
Author: Malkeet Mehra

Implement Stack using arrays.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack
{
    int start;
public:
    int a[MAX];
    Stack()
    {
        start = -1;
    }
    bool push(int x);
    bool pop();
    int top();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(start > MAX)
    {
        cout << "Error. Stack Overflow\n";
        return false;
    }
    a[++start] = x;
    return true;
}

bool Stack::pop()
{
    if(start == -1)
    {
        cout << "Error. Stack Underflow\n";
        return false;
    }
    start--;
    return true;
}

int Stack::top()
{
    if(start == -1)
    {
        cout << "Stack Empty\n";
        return -1;
    }
    return a[start];
}

bool Stack::isEmpty()
{
    return (start == -1);
}

int main()
{
    class Stack s;
    cout << s.isEmpty() << "\n";
    s.push(1);
    s.push(2);
    cout << s.top() << "\n";
    return 0;
}

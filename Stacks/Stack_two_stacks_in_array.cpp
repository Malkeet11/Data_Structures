/*****************************************************************************************************************************************

Stack_two_stacks_in_array.cpp
Created on: 03-Mar-2021
Author: Malkeet Mehra

Create a data structure twoStacks that represents two stacks. Implementation of twoStacks should use only one array, i.e.,
both stacks should use the same array for storing elements. Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack
push2(int x) –> pushes x to second stack

pop1() –> pops an element from first stack and return the popped element
pop2() –> pops an element from second stack and return the popped element

Implementation of twoStack should be space efficient.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define SZ 3

class Stack
{
    int s1;
    int s2;
public:
    int a[SZ];
    Stack()
    {
        s1 = -1;
        s2 = SZ;
    }
    bool push1(int x);
    bool push2(int x);
    int pop1();
    int pop2();
};

bool Stack::push1(int x)
{
    if(s1 >= s2-1)
    {
        cout << "Stack Overflow\n";
        return false;
    }
    a[++s1] = x;
    return true;
}

bool Stack::push2(int x)
{
    if(s1 >= s2-1)
    {
        cout << "Stack Overflow\n";
        return false;
    }
    a[--s2] = x;
    return true;
}

int Stack::pop1()
{
    if(s1 == -1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    int val = a[s1];
    --s1;
    return val;
}

int Stack::pop2()
{
    if(s2 == SZ)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    int val = a[s2];
    ++s2;
    return val;
}

int main()
{
    class Stack s;
    s.push1(1);
    //s.push1(2);
    //s.push1(3);
    s.push2(4);
    s.push2(5);
    cout << s.pop1() <<"\n";
    cout << s.pop1() <<"\n";
    cout << s.pop2() <<"\n";
    cout << s.pop2() <<"\n";
    cout << s.pop2() <<"\n";
    return 0;
}

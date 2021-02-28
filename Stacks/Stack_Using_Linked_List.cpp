/*****************************************************************************************************************************************

Stack_using_Linked_List.cpp
Created on: 28-Feb-2021
Author: Malkeet Mehra

Implement Stack using Linked List.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
    Node *root;
public:
    Stack()
    {
        root = NULL;
    }
    bool push(int x);
    int top();
    bool isEmpty();
    bool pop();
};

bool Stack::push(int x)
{
    Node *s = NULL;
    s = new Node();
    s->data = x;
    if(root == NULL){
        s->next = NULL;
    }
    else
    {
        s->next = root;
    }
    root = s;
    return true;
}

bool Stack::pop()
{
    if(!root)
    {
        cout << "Error. Stack Underflow\n";
        return false;
    }
    Node *temp = root;
    root = root->next;
    delete(temp);
    return true;
}

int Stack::top()
{
    if(root == NULL)
    {
        cout << "Stack Empty\n";
        return -1;
    }
    return root->data;
}

bool Stack::isEmpty()
{
    return (root == NULL);
}

int main()
{
    class Stack s;
    cout << s.isEmpty() << "\n";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    cout << s.top() << "\n";
    return 0;
}

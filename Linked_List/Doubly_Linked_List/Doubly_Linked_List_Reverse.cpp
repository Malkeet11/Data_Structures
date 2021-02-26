/*****************************************************************************************************************************************

Doubly_Linked_List_Reverse.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Reverse a doubly linked list.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void print(Node *head)
{
	if(head == NULL){
        cout << "NULL\n";
		return;
	}
	Node *temp = head;
	while(temp)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout <<"NULL\n";
}

void insert_end(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
	temp->data = x;

	if(head == NULL)
    {
        head = temp;
        head->next = NULL;
        head->prev = NULL;
        return;
	}
    Node *pre = head;
    while(pre->next)
        pre = pre->next;

    temp->next = NULL;
    temp->prev = pre;
    pre->next = temp;
}

// Using Nodes Swap O(N) Time and O(1) Space
void reverse_list(Node *&head)
{
    // Empty List or One item only
    if(head == NULL || head->next == NULL)
        return;

    // Swap all the Next and pre pointers. Voila.
    Node *temp = head, *x = NULL;
    while(temp)
    {
        x = temp->prev;
        temp->prev = temp->next;
        temp->next = x;
        temp = temp->prev;
    }
    head = x->prev;
}

// Using Stack O(N) Tine and O(N) Space
void reverse_list_1(Node *&head)
{
    stack<int>st;
    Node *temp = head;
    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    cout << "Head : ";print(head);
    //reverse_list(head);
    reverse_list_1(head);
    cout << "Head : ";print(head);
    return 0;
}


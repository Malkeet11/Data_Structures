/*****************************************************************************************************************************************

Doubly_Linked_List_Insertion.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Insert Data to a Doubly Linked List at :
1) At the front of the DLL
2) After a given node.
3) At the end of the DLL
4) Before a given node.

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

void insert_front(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
    temp->data = x;
    if(head == NULL)
    {
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insert_after(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    if(head->next == NULL)
    {
        temp->next = NULL;
        temp->prev = head;
        head->next = temp;
        return;
    }
    temp->next = head->next;
    temp->prev = head;
    head->next->prev = temp;
    head->next = temp;
}

void insert_before(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    if(head->prev == NULL)
    {
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_front(head, 4);
    insert_front(head, 5);
    insert_after(head->next, 6);
    insert_before(head->next->next, 6);
    cout << "Head : ";print(head);
    return 0;
}


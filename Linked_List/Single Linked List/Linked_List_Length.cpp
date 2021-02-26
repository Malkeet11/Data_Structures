/***************************************************************************

Linked_List_Length.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Write a function to count the number of nodes in a given singly linked list.

****************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print(Node *head)
{
	if(head == NULL)
		return;
	Node *temp = head;
	while(temp->next != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data << "\n";
}

void insert_end(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
	temp->data = x;
	temp->next = NULL;

	if(head == NULL)
        head = temp;
    else
    {
        Node *t = head;
        while(t ->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

int length(Node *head)
{
    int c = 0;
    while(head != NULL && ++c)
        head = head->next;
    return c;
}

int length_recursion(Node *head)
{
    if(head == NULL)
        return 0;
    return 1 + length_recursion(head->next);
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    print(head);
    cout << length(head) <<"\n";
    print(head);
    return 0;
}

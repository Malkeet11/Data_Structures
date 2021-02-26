/***************************************************************************

Linked_List_Deletion_Position.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

-- Using Position
Given a singly linked list and a position, delete a linked list
node at the given position.

Example:

Input: position = 1, Linked List = 8->2->3->1->7
Output: Linked List =  8->3->1->7

Input: position = 0, Linked List = 8->2->3->1->7
Output: Linked List = 2->3->1->7

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

void delete_pos(Node *&head, int key)
{
    Node *temp = head, *prev = head;
    int c = 1;
    if(temp != NULL && key == 1){
        head = head->next;
        delete(temp);
        return;
    }
    while(temp != NULL && c < key)
    {
        prev = temp;
        temp = temp->next;
        c++;
    }
    if(temp == NULL)
    {
        cout << "Location Not found\n";
        return;
    }
    prev->next = temp->next;
    delete(temp);
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
    delete_pos(head, 6);
    print(head);
    return 0;
}

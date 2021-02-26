/***************************************************************************

Linked_List_Deletion_Swap_Nodes.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given a linked list and two keys in it, swap nodes for two given keys.
Nodes should be swapped by changing links. Swapping data of nodes may be
expensive in many situations when data contains many fields.
It may be assumed that all keys in the linked list are distinct.

Examples:

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14

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

void swapNodes(Node *&head, int val1, int val2)
{
    Node *temp1 = head, *temp2 = head, *x = NULL, *y = NULL;
    if(val1 == val2)
    {
        cout << "Same Elements\n";
        return;
    }
    while(temp1 != NULL && temp1->data != val1)
    {
        x = temp1;
        temp1 = temp1->next;
    }
    while(temp2 != NULL && temp2->data != val2)
    {
        y = temp2;
        temp2 = temp2->next;
    }

    if(temp1 == NULL || temp2 == NULL)
    {
        cout << "Not Present\n";
        return;
    }

    if(x != NULL)
        x->next = temp2;
    else
        head = temp2;

    if(y != NULL)
        y->next = temp1;
    else
        head = temp1;

    Node *temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;
}

void swap_temp(Node *&temp1, Node *&temp2)
{
    Node *temp = temp1;
    temp1 = temp2;
    temp2 = temp;
}

void swapNodes_optimized(Node **head, int val1, int val2)
{
    Node **temp1 = NULL, **temp2 = NULL;
    if(val1 == val2)
    {
        cout << "Same Elements\n";
        return;
    }
    while((*head) != NULL)
    {
        if((*head)->data == val1)
            temp1 = head;
        if((*head)->data == val2)
            temp2 = head;
        head = &((*head)->next);
    }
    if(temp1  == NULL || temp2 == NULL)
    {
        cout << "Not Found\n";
        return;
    }
    swap_temp(*temp1, *temp2);
    swap_temp((*temp1)->next, (*temp2)->next);
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
    //swapNodes(head, 5, 1);
    swapNodes_optimized(&head, 2, 6);
    print(head);
    return 0;
}

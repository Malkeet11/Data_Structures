
/*****************************************************************************************************************************************

Linked_List_Shift.cpp
Created on: 25-Feb-2021
Author: Malkeet Mehra

Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer.
For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.
Assume that k is smaller than the count of nodes in linked list.

******************************************************************************************************************************************/
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
	cout << "NULL\n";
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

void shift_Linked_List(Node *&head, int k)
{
    Node *temp = head, *prev = NULL, *temp1 = head;
	int co = 0;
	while(temp)
	{
		co++;
		prev = temp;
		temp = temp->next;
	}
	k = k % co;
	prev->next = head;
	co -= k;
	co--;
	while(co > 0)
	{
		temp1 = temp1->next;
		co--;
	}
	head = temp1->next;
	temp1->next = NULL;

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

    shift_Linked_List(head, 2);

    print(head);
    return 0;
}


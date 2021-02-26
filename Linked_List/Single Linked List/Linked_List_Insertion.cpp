/***************************************************************************

Linked_List_Insertion.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra


****************************************************************************/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	Node *next;
	int data;
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

void insert_beg(Node **head)
{
	Node *temp = NULL;
	temp = new Node();
	cout << "Enter Data : ";
	cin >> temp->data;
	temp->next = NULL;

	if(*head == NULL)
        *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void insert_end(Node **head)
{
    Node *temp = NULL;
    temp = new Node();
    cout << "Enter Data : ";
	cin >> temp->data;
	temp->next = NULL;

	if(*head == NULL)
        *head = temp;
    else
    {
        Node *t = *head;
        while(t ->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

void insert_after(Node *prev)
{
    Node *temp = NULL;
    temp = new Node();
    cout << "Enter Data : ";
	cin >> temp->data;

	temp->next = prev->next;
	prev->next = temp;
}

int main()
{
	Node *head = NULL;
	int ch = 0;
	do
	{
		cout << "1.Insert Beginning\n2.Insert End\n3.After a Node\n4.Print\n5.Exit\nEnter Choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				insert_beg(&head);
				break;
			case 2:
				insert_end(&head);
				break;
			case 3:
				insert_after(head->next);
				break;
			case 4:
				print(head);
				break;
		}
	}
	while(ch != 5);
	return 0;
}




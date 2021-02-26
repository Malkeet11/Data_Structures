/***************************************************************************

Linked_List_Representation.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

****************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public :
	int data;
	Node *next;
};

void print(Node *h)
{
	if(h == NULL)
		return;
	Node *temp = h;
	while(temp->next != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data;
}
int main()
{
	Node *head = NULL, *first = NULL, *second = NULL;
	head = new Node();
	head->data = 1;
	head->next = NULL;

	first = new Node();
	first->data = 2;
	first->next = NULL;
	head->next = first;

	second = new Node();
	second->data = 3;
	second->next = NULL;
	first->next = second;

	print(head);
	return 0;
}


/*****************************************************************************************************************************************

Singly_Insertion.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

In circular Linked List, add data at:
a) End
b) Beginning
c) After a node(Data Key is given)

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
	Node *temp = head->next;
	while(temp != head)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data <<"->Back\n";
}

void insert_end(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
	temp->data = x;

	if(head == NULL)
    {
        head = temp;
        head->next = head;
	}
    else
    {
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
}

void insert_front(Node *&head, int x)
{
    Node *temp = NULL;
    temp = new Node();
    temp->data = x;

    if(head == NULL)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
    }
}

void insert_after(Node *&head, int x, int k)
{
    Node *temp = NULL;
    temp = new Node();
    temp->data = x;

    Node *s = head->next;
    while(s->data != k && s != head)
        s = s->next;

    if(s == head)
    {
        if(s->data == k)
        {
            temp->next = s->next;
            s->next = temp;
            head = temp;
        }
        else
            cout << "Key Not found\n";
        return;
    }
    temp->next = s->next;
    s->next = temp;
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_front(head, 3);
    insert_front(head, 4);
    insert_front(head, 5);
    insert_after(head, 6, 1);
    print(head);

    return 0;
}


/***************************************************************************

Linked_List_Deletion.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra
--Using Key
Given a ‘key’, delete the first occurrence of this key in the linked list.

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

void insert_end(Node **head, int x)
{
    Node *temp = NULL;
    temp = new Node();
	temp->data = x;
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

void delete_key(Node **head, int key)
{
    Node *temp = *head;
    Node *del;
    if(temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        del = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Not Found\n";
        return;
    }
    del->next = temp->next;
    delete(temp);
}

void delete_key_recursion(Node *&head, int key)
{
    if(head == NULL)
    {
        cout << "Not Found";
        return;
    }
    if(head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete(temp);
        return;
    }
    delete_key_recursion(head->next, key);
}


int main()
{
    Node *head = NULL;
    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);
    print(head);
    //delete_key(&head, 5);
    delete_key_recursion(head, 5);
    print(head);
    return 0;
}


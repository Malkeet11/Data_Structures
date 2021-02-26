/*****************************************************************************************************************************************

Doubly_Linked_List_Deletion.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Delete a given node in a doubly linked list.

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

void delete_node(Node *&head, Node *del)
{
    // Empty List
    if(head == NULL)
        return;
    // End Element
    if(del->next == NULL)
    {
        del->prev->next = NULL;
        delete(del);
        return;
    }
    // 1st Element
    if(head == del)
    {
        head->next->prev = NULL;
        head = head->next;
        delete(del);
        return;
    }
    // Any Middle Element
    del->next->prev = del->prev;
    del->prev->next = del->next;
    delete(del);
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
    delete_node(head, head->next->next->next->next);
    cout << "Head : ";print(head);
    return 0;
}


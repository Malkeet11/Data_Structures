/***************************************************************************

Linked_List_Reverse.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given pointer to the head node of a linked list, the task is to reverse
the linked list. We need to reverse the list by changing the links
between nodes.

Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL

Input: Head of following linked list
1->2->3->4->5->NULL
Output: Linked list should be changed to,
5->4->3->2->1->NULL

Input: NULL
Output: NULL

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
    {
        cout << "NULL\n";
		return;
	}
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout  << "NULL\n";
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

void reverse_ll(Node *&head)
{
    Node *temp = NULL;
    Node *cur = head;
    Node *pre = NULL;
    while(cur != NULL)
    {
        pre = cur;
        cur = cur->next;
        pre->next = temp;
        temp = pre;
    }
    head = temp;
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
    reverse_ll(head);
    print(head);
    return 0;
}

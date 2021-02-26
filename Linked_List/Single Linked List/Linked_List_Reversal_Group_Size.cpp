/***************************************************************************

Linked_List_Reversal_Group_Size.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given a linked list, write a function to reverse every k nodes
(where k is an input to the function).

Example:

Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL
Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL

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

void reverse_size(Node *&head, int k)
{
    Node *temp = NULL,*temp1 = NULL, *cur = head, *pre = NULL, *next = NULL;
    int c = 0;
    while(true)
    {
        if(!cur)
            return;
        while(cur && c < k)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            c++;
        }
        if(temp1 == NULL)
            temp1 = pre;
        else
            temp1->next = pre;
        c = 0;
        //print(temp1);
    }
    head = temp1;
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
    reverse_size(head, 3);
    print(head);
    return 0;
}

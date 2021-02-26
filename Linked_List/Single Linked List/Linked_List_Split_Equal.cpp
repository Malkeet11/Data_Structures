
/*****************************************************************************************************************************************

Linked_List_Split_Equal.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Split a Linked List into two halves.
If there are odd number of nodes, then first list should contain one extra.

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

// Using Two pointers
void split(Node *&head, Node *&head1, Node *&head2)
{
    Node *slow = head, *fast = head, *prev = NULL;
    while(slow && fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL)
    {
        head1 = head;
        head2 = prev->next;
        prev->next = NULL;
    }
    else
    {
        head1 = head;
        head2 = slow->next;
        slow->next = NULL;
    }
    head = NULL;
}

int main()
{
    Node *head = NULL, *head1 = NULL, *head2 = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    cout << "Head : "; print(head);
    cout << "Head 1 : "; print(head1);
    cout << "Head 2 : "; print(head2);
    split(head, head1, head2);
    cout << "Head : "; print(head);
    cout << "Head 1 : "; print(head1);
    cout << "Head 2 : "; print(head2);
    return 0;
}


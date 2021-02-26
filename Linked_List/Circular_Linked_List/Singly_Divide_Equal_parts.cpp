
/*****************************************************************************************************************************************

Singly_Middle_Element.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Find Middle Element of Circular Linked List.

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

void divide_parts(Node *&head, Node *&head1, Node *&head2)
{
    Node *slow = head->next, *fast = head->next, *temp = NULL;
    while(fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == head)
        fast = fast->next;
    temp = fast->next;
    fast->next = slow->next;
    head2 = fast;

    slow->next = temp;
    head1 = slow;
}

int main()
{
    Node *head = NULL, *head1 = NULL, *head2 = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    print(head);
    print(head1);
    print(head2);
    divide_parts(head, head1, head2);
    print(head);
    print(head1);
    print(head2);

    return 0;
}


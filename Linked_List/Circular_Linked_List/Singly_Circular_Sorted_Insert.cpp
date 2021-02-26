
/*****************************************************************************************************************************************

Singly_Circular_Sorted_Insert.cpp
Created on: 26-Feb-2021
Author: Malkeet Mehra

Insert a new value in a sorted Circular Linked List (CLL).
Example :
Input :
1->2->4->5->Back_to_1
Insert 3,

Output :
1->2->3->4->5->Back_to_1

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

void insert_sorted(Node *&head, int x)
{
    // Creating New Node
    Node *temp;
    temp = new Node();
    temp->data = x;

    // If List is Empty
    if(head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }

    // If added on first node
    if(head->next->data > x)
    {
        temp->next = head->next;
        head->next = temp;
        return;
    }

    // If added on last node
    if(head->data < x)
    {
        temp->next = head->next;
        head->next = temp;
        head = temp;
        return;
    }
    // After any inner node
    Node *pre = head->next;
    while(pre->next->data < x)
        pre = pre->next;
    temp->next = pre->next;
    pre->next = temp;
}

int main()
{
    Node *head = NULL, *head1 = NULL, *head2 = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    //insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    cout << "Head : ";print(head);
    insert_sorted(head,3);
    cout << "Head : ";print(head);
    return 0;
}


/*****************************************************************************************************************************************

Linked_List_Two_Sum.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given two numbers represented by two lists, write a function that returns the sum list.
The sum list is list representation of the addition of two input numbers.

Example:

Input:
List1: 5->6->3 // represents number 365
List2: 8->4->2 // represents number 248
Output:
Resultant list: 3->1->6 // represents number 613
Explanation: 365 + 248 = 613
Input:
List1: 7->5->9->4->6 // represents number 64957
List2: 8->4 // represents number 48
Output:
Resultant list: 5->0->0->5->6 // represents number 65005
Explanation: 64957 + 48 = 65005

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

void add(Node *&head, Node *&head1, Node *&head2)
{
    int car = 0, temp = 0;
    Node *x;
    while(head1 && head2)
    {
        temp = (head1->data + head2->data + car);
        insert_end(head, temp%10);
        car = temp/10;
        x = head1;
        head1 = head1->next;
        delete(x);
        x = head2;
        head2 = head2->next;
        delete(x);
    }
    // If 1st Number is non Empty
    while(head1)
    {
        temp = (head1->data + car);
        insert_end(head, temp%10);
        car = temp/10;
        x = head1;
        head1 = head1->next;
        delete(x);
    }
    // If 1st Number is non Empty
    while(head2)
    {
        temp = (head2->data + car);
        insert_end(head, temp%10);
        car = temp/10;
        x = head2;
        head2 = head2->next;
        delete(x);
    }
    // If Carry is non Empty
    if(car)
        insert_end(head, car);
}

int main()
{
    Node *head = NULL, *head1 = NULL, *head2 = NULL;
    insert_end(head1, 5);
    insert_end(head1, 9);
    insert_end(head1, 4);
    insert_end(head2, 6);
    insert_end(head2, 8);
    insert_end(head2, 7);
    cout << "1st : "; print(head1);
    cout << "2nd : "; print(head2);
    cout << "Output : "; print(head);
    add(head, head1, head2);
    cout << "\n\n";
    cout << "Output : "; print(head);
    cout << "1st : "; print(head1);
    cout << "2nd : "; print(head2);
    return 0;
}


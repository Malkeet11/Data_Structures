
/*****************************************************************************************************************************************

Linked_List_Shift.cpp
Created on: 25-Feb-2021
Author: Malkeet Mehra

Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5
then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element.
For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

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

// Using Counter to find length and iterating till length/2
int mid_element_1(Node *head)
{
    Node *temp = head;
    int c = 0;
    if(head == NULL || head->next == NULL)
    {
        cout << "No middle Elements present";
        return -1;
    }
	while(temp)
    {
        temp = temp->next;
        c++;
    }
    c /= 2;
    temp = head;
    while(c--)
        temp = temp->next;
    return temp->data;
}

// Using Two pointers
int mid_element_2(Node *head)
{
    Node *slow = head, *fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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
    cout << mid_element_1(head) <<"\n";
    cout << mid_element_2(head) <<"\n";
    return 0;
}


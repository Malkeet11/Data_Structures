
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

int middle_element(Node *head)
{
    Node *slow = head, *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while(fast != head && fast->next != head);
    return slow->next->data;
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    //insert_end(head, 5);
    print(head);
    cout << middle_element(head) <<"\n";
    return 0;
}


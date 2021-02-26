/*****************************************************************************************************************************************

Linked_List_Merge_Sorted_Linked_Lists.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Write a SortedMerge() function that takes two lists, each of which is sorted in increasing order,
and merges the two together into one list which is in increasing order. SortedMerge() should return the new list.
The new list should be made by splicing together the nodes of the first two lists.

For example if the first linked list a is 5->10->15 and the other linked list b is 2->3->20, then SortedMerge()
should return a pointer to the head node of the merged list 2->3->5->10->15->20.

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

/**** Creating new Nodes and deleting existing ****/

void merge_list(Node *&head1, Node *&head2, Node *&head)
{
    Node *temp1 = head1, *temp2 = head2, *temp;
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            insert_end(head, head1->data);
            temp = head1;
            head1 = head1->next;
            delete(temp);
        }
        else
        {
            insert_end(head, head2->data);
            temp = head2;
            head2 = head2->next;
            delete(temp);
        }
    }
    while(head1)
    {
        insert_end(head, head1->data);
        temp = head1;
        head1 = head1->next;
        delete(temp);
    }
    while(head2)
    {
        insert_end(head, head2->data);
        temp = head2;
        head2 = head2->next;
        delete(temp);
    }
}

/****** Utilizing existing Nodes *********/

void merge_list_2(Node *&head1, Node *&head2, Node *&head)
{
    Node *temp, *x = head;
    while(1)
    {
        if(head1 == NULL && head2 == NULL)
            return;
        else if(head1 == NULL)
        {
            if(x == NULL)
            {
                head = head2;
                return;
            }
            x->next = head2;
            return;
        }
        else if(head2 == NULL)
        {
            if(x == NULL)
            {
                head = head1;
                return;
            }
            x->next = head1;
            return;
        }
        else
        {
            if(head1->data < head2->data)
            {
                temp = head1;
                head1 = head1->next;
                temp->next = NULL;
                if(head == NULL)
                {
                    head = temp;
                    x = head;
                }
                else
                {
                    x->next = temp;
                    x = x->next;
                }
            }
            else
            {
                temp = head2;
                head2 = head2->next;
                temp->next = NULL;
                if(head == NULL)
                {
                    head = temp;
                    x = head;
                }
                else
                {
                    x->next = temp;
                    x = x->next;
                }
            }
        }
    }
}

int main()
{
    // Node 1
    Node *head1 = NULL;
    insert_end(head1, 1);
    insert_end(head1, 3);
    insert_end(head1, 5);
    insert_end(head1, 7);
    insert_end(head1, 9);
    print(head1);

    //Node 2
    Node *head2 = NULL;
    insert_end(head2, 2);
    insert_end(head2, 4);
    insert_end(head2, 6);
    insert_end(head2, 8);
    insert_end(head2, 10);
    print(head2);

    //Ans in Head Node
    Node *head = NULL;

    //Calling Merge Function

    //Merging using New nodes
    //merge_list(head1, head2, head);

    //Merging using existing Nodes
    merge_list_2(head1, head2, head);

    //Printing Answer
    print(head);
    print(head1);
    print(head2);
    return 0;
}

/*****************************************************************************************************************************************

Linked_List_Loop_Check.cpp
Created on: 25-Feb-2021
Author: Malkeet Mehra

Given a linked list, check if the linked list has loop or not.

Example:

Input:
List1: 1->2->3->4->5--
             ^       |
             |       |
             |       |
             ---------
Output:
Yes

Input:
List1: 1->2->3->NULL
Output:
NO

Also, Remove if found.

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

// Using Hashing O(N) Time and O(N) Space Complexity. Space can be reduced by using flag key in Class Node
// which will check for the already visited Node
void check_loop_1(Node *head)
{
    unordered_set<Node *> s;
    while(head)
    {
        if(s.find(head) == s.end())
            s.insert(head);
        else
        {
            cout << "YES\n";
            return;
        }
        head = head->next;
    }
    cout << "NO\n";
}

// Flyod's Cycle Finding Method -

void check_loop_2(Node *head)
{
    Node *slow = head, *fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

// Find & Remove Loop using Hashing

void remove_loop_hashing(Node *head)
{
    unordered_set<Node *> s;
    Node *temp;
    while(head)
    {
        if(s.find(head) == s.end()){
            temp = head;
            s.insert(head);
            head = head->next;
        }
        else
        {
            temp->next = NULL;
            return;
        }
    }
}

/*********************************************************************************************************************

Finding Loop using Floyd Warshall and then,
After detecting the loop, if we start slow pointer from head and move both slow and fast pointers
at same speed until fast don’t meet, they would meet at the beginning of the loop.

**********************************************************************************************************************/
void remove_loop_2(Node *head)
{
    Node *slow = head, *fast = head;
    // Base Condition No Loop
    if(head == NULL || head->next == NULL)
        return;
    while(slow && fast && fast->next)
    {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next;
    }
    // No Loop
    if(slow != fast)
        return;
    slow = head;

    // Loop at Start Node
    if(fast == head)
    {
        while(fast->next != slow)
            fast = fast->next;
    }
    else
    {
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // Removing Loop
    fast->next = NULL;
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

    // Creating Loop
    head->next->next->next->next->next = head;
    check_loop_1(head);
    //check_loop_2(head);

    /*** Removing Loop ***/
    //remove_loop_hashing(head);
    remove_loop_2(head);

    check_loop_1(head);
    print(head);
    return 0;
}


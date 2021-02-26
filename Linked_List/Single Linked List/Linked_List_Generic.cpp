
/*****************************************************************************************************************************************

Linked_List_Generic.cpp
Created on: 25-Feb-2021
Author: Malkeet Mehra

Create a linked list that can be used for any data type.

Alternative approach : Can be done using void pointer for data field.

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T> *next;
};
template<class T>
void print(Node<T> *head)
{
	if(head == NULL){
        cout << "NULL\n";
		return;
	}
	Node<T> *temp = head;
	while(temp)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}
template<class T>
void insert_end(Node<T> *&head, T x)
{
    Node<T> *temp = NULL;
    temp = new Node<T>();
	temp->data = x;
	temp->next = NULL;

	if(head == NULL)
        head = temp;
    else
    {
        Node<T> *t = head;
        while(t ->next != NULL)
            t = t->next;
        t->next = temp;
    }
}
int main()
{
    Node<string> *head = NULL;
    for(int i = 1; i <= 5; i++)
        insert_end(head, "{"+to_string(i)+"}");

    print(head);

    return 0;
}


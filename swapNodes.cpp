#include <bits/stdc++.h>
using namespace std;

class Node
{
public:

	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* temp = new Node(data);

	if(!head)
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}
}

int lengthOfLinkedList(Node* head)
{
	int length = 0;

	while(head)
	{
		head = head->next;
		length++;
	}

	return length;
}

void printLinkedList(Node* head)
{
	while(head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

Node* swapNodes(Node* head, int k)
{
	Node* first = head, *second = head, *prevFirst, *prevSecond, *temp, *pointer = head;
	k --;

	while(k--)
	{
		prevFirst = first;
		first = first->next;
	}
	
	if(head == first)
	{
		while(second && second->next && second->next->next)
			second =  second->next;

		second->next->next = first->next;
		head = second->next;
		second->next = first;
		first->next = NULL;
	}
	else
	{
		pointer = first;
		while(pointer->next)
		{
			prevSecond = second;
			second = second->next;
			pointer = pointer->next;
		}

		prevFirst->next = second;
		prevSecond->next = first;
		temp = first->next;
		first->next = second->next;
		second->next = temp;
	}

	return head;
}

int main()
{
	Node* head = NULL;
	int k,length;

	while(1)
	{
		int data;
		cin >> data;

		if(data == -1)
			break;
		else
			insertAtHead(head,data);
	}

	printLinkedList(head);
	length = lengthOfLinkedList(head);

	cin >> k;
	cout << length << endl;

	head = swapNodes(head,k);
	printLinkedList(head);

	return 0;
}
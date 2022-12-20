#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int data)
{
    Node *temp = new Node(data);

    if(!head)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}


Node* deleteList(Node *head, Node *first, Node *second, Node* secondHead, Node* secondTail)
{
    Node *firstPrev = NULL, *secondNext, *pointer = head, *newHead;

    while(pointer->next)
    {
        if(pointer->next == first)
            firstPrev = pointer;
        if(pointer == second)
            secondNext = pointer->next;

        pointer = pointer->next;
    }

    if(!firstPrev)
    {
        newHead = secondHead;
        secondTail->next = secondNext;
    }
    else if(!secondNext)
    {
        newHead = head;
        firstPrev->next = secondHead;
    }
    else
    {
        newHead = head;
        firstPrev->next = secondHead;
        secondTail->next = secondNext;
    }

    return newHead;
}

void printLinkedList(Node *head)
{
    while(head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *headOne = NULL, *headTwo = NULL;

    insertAtHead(headOne,10);
    insertAtHead(headOne,20);
    insertAtHead(headOne,30);
    insertAtHead(headOne,40);
    insertAtHead(headOne,50);

    printLinkedList(headOne);

    insertAtHead(headTwo,60);
    insertAtHead(headTwo,70);
    insertAtHead(headTwo,80);
    insertAtHead(headTwo,90);
    insertAtHead(headTwo,95);

    printLinkedList(headTwo);

    Node* first, *second, *pointer = headOne, *newHead, *secondTail;

    while(pointer)
    {
        if(pointer->data == 40)
            first = pointer;
        if(pointer->data == 30)
            second = pointer;

        pointer = pointer->next;
    }

    pointer = headTwo;
    while(pointer->next)
        pointer = pointer->next;
    secondTail = pointer;

    newHead = deleteList(headOne,first,second,headTwo,secondTail);

    printLinkedList(newHead);

    return 0;
}
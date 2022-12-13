#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertAtHead(Node** head,int data)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if(!*head)
        *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void insertAtEnd(Node** head,int data)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if(!*head)
        *head = temp;
    else
    {
        Node* tempHead = *head;
        while(tempHead->next)
            tempHead = tempHead->next;
        tempHead->next = temp;
    }
}

void insertBefore(Node** head,int data,int dataBefore)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if((*head)->data == dataBefore)
        insertAtHead(head,data);
    else
    {
        Node* tempHead = *head;
        while(tempHead->next->data != dataBefore)
            tempHead = tempHead->next;
        temp->next = tempHead->next;
        tempHead->next = temp;
    }
}

void printLinkedList(Node* head)
{
    if(!head)
        printf("Empty Linked List...\n");
    else
    {
        while(head)
        {
            printf("%d ",head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main()
{
    Node* head = NULL;
    
    printLinkedList(head);

    insertAtEnd(&head,10);
    printLinkedList(head);

    insertAtEnd(&head,20);
    printLinkedList(head);

    insertAtEnd(&head,30);
    printLinkedList(head);

    insertAtEnd(&head,40);
    printLinkedList(head);

    insertAtEnd(&head,50);
    printLinkedList(head);

    insertBefore(&head,0,10);
    printLinkedList(head);

    insertBefore(&head,15,20);
    printLinkedList(head);

    insertBefore(&head,45,50);
    printLinkedList(head);

    return 0;
}
#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

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

void deletionAtEnd(Node** head)
{
    if(!(*head)->next)
    {
        free(*head);
        *head =  NULL;
    }
    else
    {
        Node* tempHead = *head;
        while(tempHead->next->next)
            tempHead = tempHead->next;
        free(tempHead->next);
        tempHead->next = NULL;
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

    deletionAtEnd(&head);
    printLinkedList(head);

    return 0;
}
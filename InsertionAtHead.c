#include <stdio.h>
#include <stdlib.h>

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

    insertAtHead(&head,10);
    printLinkedList(head);

    insertAtHead(&head,20);
    printLinkedList(head);

    insertAtHead(&head,30);
    printLinkedList(head);

    insertAtHead(&head,40);
    printLinkedList(head);

    insertAtHead(&head,50);
    printLinkedList(head);

    return 0;
}
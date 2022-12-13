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

// By using Hair ans Tortoise or Slow and Fast Pointer

int middleElementOfLinkedList(Node* head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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

    printf("%d\n",middleElementOfLinkedList(head));

    insertAtEnd(&head,60);
    printLinkedList(head);

    printf("%d\n",middleElementOfLinkedList(head));

    return 0;
}
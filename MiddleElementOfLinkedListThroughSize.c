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

int sizeOfLinkedList(Node* head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// By using size of the linked list

int midThroughSize(Node* head)
{
    int length = sizeOfLinkedList(head), mid;
    if(length&1)
        mid = length/2;
    else
        mid = length/2 - 1;
    while (mid--)
        head = head->next;
    return head->data;
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

    printf("%d\n",midThroughSize(head));

    insertAtEnd(&head,50);
    printLinkedList(head);

    printf("%d\n",midThroughSize(head));

    return 0;
}
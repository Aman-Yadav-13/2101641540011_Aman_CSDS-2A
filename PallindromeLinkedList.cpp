//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    Node* middleLinkedList(Node* head)
    {
        Node* hare = head, *tortoise = head;
        while(hare&& hare->next && hare->next->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise->next;
    }
    
    Node* reverseLinkedList(Node* head)
    {
        if(!head || !(head->next))
            return head;
        Node*newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* mid = middleLinkedList(head); 
        Node* newHead = reverseLinkedList(mid);
        while(newHead)
        {
            if(newHead->data != head->data)
                return false;
            newHead = newHead->next;
            head = head->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
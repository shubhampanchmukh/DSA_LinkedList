// { Driver Code Starts
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
  public:
    Node *reverse1(Node *head){
        Node* cur=head;
        Node *prev=NULL,*next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
            return prev;
    }
    Node *findMid(Node *head){
        Node *slow=head;
       Node *fast=head;
     
       if(head!=NULL){
        while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }
       }
        return slow;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *mid=findMid(head);
        Node* newHead=reverse1(mid);
        while(head!=mid){
        if(head->data==newHead->data )
        {
            head=head->next;
            newHead=newHead->next;

        }
        else return 0;
        }
        return 1;
        
    }
};



// { Driver Code Starts.
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
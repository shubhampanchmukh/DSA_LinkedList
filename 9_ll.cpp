// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};



void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:

    Node* reverse(Node* head)
    {
        Node* current =head;
        Node *prev =NULL, *next =NULL;

        while( current !=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;   
    }

    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        bool f=true;
        Node* cur=head;
        while(cur!=NULL && f==true){
            if(cur->next==NULL and cur->data==9){
                cur->data=1;
                Node* temp=new Node(0);
                temp->next=head;
                head=temp;
                cur=cur->next;
            }
            else if(cur->data==9){
                cur->data=0;
                cur=cur->next;
            }
            else{
                cur->data=cur->data +1;
                cur=cur->next;
                f=false;
            }
        }
        head=reverse(head);
        return head;

    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
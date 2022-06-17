#include <bits/stdc++.h>
  
using namespace std;
  
// a node of the doubly linked list
struct Node {
    int data;
    Node *next, *prev;
};
  
// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}
  
// function to insert a node at the beginning
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
  
    // link the old list off the new node
    new_node->next = (*head_ref);
  
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
  
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
   if(head==NULL ||k==1){
    return head;
   }

   Node *dummy= new Node();

   dummy->next=head;
   

   Node *cur=dummy, *nex=dummy,*pre=dummy;
    int count=0;
   while(cur->next!=NULL){
    cur=cur->next;
    count++;
   }

   while(count>=k)
   {
        cur=pre->next;
        nex=cur->next;
        for(int i=1;i<k;i++){
        cur->next=nex->next;
        nex->next=pre->next;
        pre->next=nex;
        nex=cur->next;
        }
        
        pre=cur;
        count-=k;

   }
   return dummy->next;

}
 
// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
  
// Driver program to test above
int main()
{
    // Start with the empty list
    Node* head = NULL;
  
    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
     
    int k = 2;
  
    cout << "Original list: ";
    printList(head);
  
    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);
  
    cout << "\nModified list: ";
    printList(head);
  
    return 0;
}
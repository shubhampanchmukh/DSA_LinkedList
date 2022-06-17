#include <bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.
void pairSum(struct Node *head, int x)
{
    Node *first = head;
    Node *second=head;
    
    while(second->next!=NULL){
        second=second->next;
    }
   
    bool found=false;

    while ( first!=second && second->next!= first)
    {
        if(first->data+second->data==x){
            found=true;
            cout<<"("<<second->data<<", "<<first->data<<")"<<endl;
            first=first->next;
            second=second->prev;
        }
        else if(first->data+second->data > x){
            second=second->prev;
        }
        else{
            first=first->next;
        }
    }
    if(found==false){
        cout<<"No pairs found.";
    }
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;

    pairSum(head, x);

    return 0;
}
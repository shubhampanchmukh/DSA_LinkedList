#include <bits/stdc++.h>
 
using namespace std;
 
// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};
 
//Brute force method having 0(N^3) TC! 
// int countTriplets(struct Node* head, int x)
// {
//     Node* ptr1,*ptr2,*ptr3;
//     int count=0;

//     for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next){
//         for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
//             for(ptr3=ptr2->next;ptr3!=NULL;ptr3=ptr3->next){
//                 if(ptr1->data+ptr2->data+ptr3->data==x){
                    
//                     count++;

//                 }
//             }
//         }
//     }
//     return count;
// }

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'

//Method 3 Efficient Approach(Use of two pointers): 
int countTriplets(struct Node* head, int x)
{
    Node* first=head;
    Node* second=head->next;
    Node* third=head;
    int count=0;

bool found=false;

    while(third->next!=NULL){
        third=third->next;
    }
    while(third!=second && third->next!=second)
        {
    for(first=head;first!=NULL;first=first->next){
        int y=x-first->data;
        
        for(second=first->next;second!=NULL;second=second->next)
        {
            if(y==second->data+third->data){
                found=true;
                cout<<"("<<first->data<<", "<<second->data<<", "<<third->data<<")"<<endl;
                count++;
                if(third->prev!=first) {third=third->prev;}

            }
            else if(y<second->data+third->data){
                third=third->prev;
            }
            else
            {
                second=second->next;
            }  
        
        }
    }
     return count;
    }

   if(found==false || count==0){
    cout<<endl<<"No triplet found!!";
   }
    
}
 
// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
    // allocate node
    struct Node* temp = new Node();
 
    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node* head = NULL;
 
    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "<< countTriplets(head, x);
    return 0;
}





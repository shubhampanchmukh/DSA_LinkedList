// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if(head==NULL){
            return NULL;
        }
        int count = 0;
        node *current = head;
        node *prev = NULL;
        node *temp = NULL;

        while (current != NULL && count < k)
        {

            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
        }
        if (temp != NULL)
        {
            head->next = reverse(temp, k);
        }
        return prev;
    }
};

// { Driver Code Starts.

/* Driver program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

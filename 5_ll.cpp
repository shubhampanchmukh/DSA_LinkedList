#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        // if(head==NULL){
        //     cout<<"Loop does not exist!!"<<endl;
        //     return false;
        // }

        // map<Node*,bool> visited;

        // Node* temp=head;
        // while(head!=NULL)
        // {
        //     if(visited[temp]==true){
        //         cout<<"Starting point of the loop is: "<<temp->data<<endl;
        //         return 1;
        //     }
        //     visited[temp]=true;
        //     temp=temp->next;
        // }

        // return false;
    }

    //---------------------//

    // Floyds detect method!!!
    Node *floydDetectLoop(Node *head)
    {
        if (head == NULL)
        {
            cout << "Loop does not exist!!" << endl;
            return NULL;
        }

        Node *slow = head;
        Node *fast = head;

        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {

                return slow;
            }
        }
        return NULL;
    }

    void print(Node *head) // for circular ll
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        else
        {
           
            int first = temp->data;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            {
                // cout<< first<<" ";
            }
            // cout<<endl;
        }
    }
    Node *getstartingNode(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *intersection = floydDetectLoop(head);
        Node *slow = head;

        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }

    void removeLoop(Node *head)
    {
        if (head == NULL)
        {
            return;
            }
            else{
            Node *startOfLoop = getstartingNode(head);
            Node *temp = startOfLoop;

            while (temp->next != startOfLoop)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        if (ob.detectLoop(head) || ob.floydDetectLoop(head))
        {
            cout << "True\n";
            // ob.print(head);
            cout << "Starting point of the loop is: " << ob.getstartingNode(head)->data << endl;
            ob.removeLoop(head);
            ob.print(head);
        }
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
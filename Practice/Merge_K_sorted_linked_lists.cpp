// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
/* 4
3 1 2 3 2 4 5 2 5 6 2 7 8 */
class Solution
{
/* public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        multimap<int, Node *> mm;
        Node *head = NULL;
        for (int i = 0; i < K; i++)
        {
            Node *temp = arr[i];
            mm.insert({temp->data,temp});
            while (temp != NULL)
            {
                mm.insert({temp->data, temp});
                temp = temp->next;
            }
        }

        if (!mm.empty())
        {
            auto it = mm.begin();
            head = it->second;
            it++;
            mm.erase(mm.find(head->data));
            Node *temp2 = it->second;
            while (!mm.empty())
            {
                it++;
                mm.erase(mm.find(temp2->data));
                if(mm.empty())
                {
                    break;
                }
                temp2->next = it->second;
                temp2 = temp2->next;
            }
            temp2->next = NULL;
        }
        return head;
    } */
    public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<int, vector<int>, greater<int>> pq;
           for(int i=0;i<K;i++)
           {
               while(arr[i])
               {
                   pq.push(arr[i]->data);
                   arr[i]=arr[i]->next;
               }
           }
           Node *head = new Node(pq.top());
           pq.pop();
           Node *tail = head;
           while(pq.empty()==false)
           {
               Node *curr = new Node(pq.top());
               pq.pop();
               tail->next = curr;
               tail=tail->next;
           }
        return head;
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends
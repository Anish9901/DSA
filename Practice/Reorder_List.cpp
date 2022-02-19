// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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

void reorderList(Node* head) {
    deque<Node *>dq;
    Node *copy = head,*temp = NULL;
    while (copy!=NULL)
    {
        dq.push_back(copy);
        copy = copy->next;
    }
    
    while(!dq.empty())
    {
        if(dq.size() == 1)
        {
            dq.front()->next = NULL;
            break;
        }
        else if(dq.size() == 2)
        {
            dq.front()->next = dq.back();
            dq.back()->next = NULL;
            break;
        }
        temp = dq.front()->next;
        dq.front()->next = dq.back();
        dq.back()->next = temp;
        dq.pop_front();
        dq.pop_back();
    }
    // Your code here
}
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node* head = NULL,*temp = head_ref,*temp2 = NULL;
        //Node*i,*j;
        while(temp!=NULL)
        {
            int x = temp->data;
			Node* newnode = new Node(x);
            if(head == NULL)
            {
                head = newnode;
                temp2 = head;
            }
            else if(temp2 == head && temp2->data >= x)//case 1
            {
                newnode->next = temp2;
                head = newnode;
                temp2 = newnode;
            }
            else if(temp2 == head && temp2->data <= x)
            {
                while(temp2->next != NULL && temp2->next->data <= x)
                {
                    temp2 = temp2->next;
                }
                newnode ->next = temp2->next;
                temp2->next = newnode;
				temp2 = head;
            }
            /* else
            {
                temp2->next = new Node(x);
                temp2 = temp2->next;
            } */
            temp = temp->next;
        }
		return head;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends
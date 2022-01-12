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
    Node* addOne(Node *head) 
    {
        /* stack<int> st;
        Node *ptr = head;
        string str = "";
        int i = 0;
        while(ptr!= NULL)
        {
            st.push(ptr->data);
            ptr = ptr->next;
        }

        int j = 0;
        int sizeofstack = st.size();
        for(int i = 0; i<sizeofstack ;i++)
        {
            j += st.top() * pow(10,i);
            st.pop();
        }

        j++;
        cout<<"j= "<<j<<endl;
        str = to_string(j);
        //cout<<"str = "<<str<<endl; 
        ptr = head;
        for(int i = 0; i<str.size();i++)
        {
            ptr->data = str[i] - '0' ;
            ptr = ptr->next;
        } */
        Node* reversed = Reverse(head);
        Node* finalhead;
        Node *ptr = reversed;
        Node *prev = NULL;
        if(ptr->data == 9 && ptr != NULL)
        {
            while(ptr->data==9 && ptr->next != NULL)
            {
                ptr->data = (ptr->data + 1)%10;
                ptr = ptr->next;
            }
            ptr->data = ptr->data + 1;

        }
        else
        {
            ptr->data = ptr->data + 1;
        }
        finalhead = Reverse(reversed);
        return finalhead;
       
    }
    Node* Reverse(Node *head)
    {
        Node *ptr1 = NULL;
        Node *ptr2 = head;
        Node *ptr3 = NULL;
        if(ptr2->next != NULL)
        {
            ptr3 = ptr2->next;
        }
        while(ptr2 != NULL && head != NULL)
        {
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            if(ptr3 !=NULL)
            {
                ptr3 = ptr3->next;
            }
        }
        head = ptr1;
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
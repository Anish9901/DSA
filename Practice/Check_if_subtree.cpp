// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

class Solution
{
public:
    /* int height(Node *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        //height of left subtree
        int l = 1 + height(root->left);
        //height of right subtree
        int r = 1 + height(root->right);

        if(l>r)
        {
            return l;
        }
        else
        {
            return r;
        }

    } */
    bool helper(Node *root, Node *subroot)
    {
        // Base Case
        if (root == NULL && subroot == NULL)
        {
            return true;
        }
        if (root == NULL || subroot == NULL)
        {
            return false;
        }
        return (root->data == subroot->data && helper(root->left,subroot->left) && helper(root->right,subroot->right));
    }
    bool traverse(Node *root, Node *subroot)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }
        if(helper(root, subroot))
        {
            return true;
        }
        return traverse(root->left, subroot)||traverse(root->right, subroot);
        
    }
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node *T, Node *S)
    {
        
        if (S == NULL)
        {
            return true;
        }
        if (T == NULL)
        {
            return false;//Nahi toh segfault ayega due to the return statement below
        }
        if(helper(T, S))
        {
            return true;
        }
        return traverse(T,S);
        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";
    }
    return 0;
} // } Driver Code Ends
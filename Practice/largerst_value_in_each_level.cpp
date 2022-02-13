// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int height(Node* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        int l = 1 + height(node->left);
        int r = 1 + height(node->right);
        if(l > r)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
    void levelorder(Node *node,int level,int &max)
    {
        if(node == NULL || level<=0)
        {
            return;
        }
        if(level == 1 && node->data > max)
        {
            max = node->data;
        }
        else if(level>1)
        {
            levelorder(node->left,level-1,max);
            levelorder(node->right,level-1,max);
        }
    }
    vector<int> largestValues(Node* root)
    {
        vector<int> res;
        int h = height(root);
        for(int i = 1; i<=h; i++)
        {
            int max = INT_MIN;
            levelorder(root,i,max);
            res.push_back(max);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    getchar();
    while (t--)
    {

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);
        Solution ob;
        vector<int> ans = ob.largestValues(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
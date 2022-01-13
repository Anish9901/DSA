// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

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
    Node *root = newNode(stoi(ip[0]));

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = 1 + height(root->left);
    int r = 1 + height(root->right);
    if (l > r)
    {
        return l;
    }
    else
    {
        return r;
    }
}

void helper(Node *root, int level, vector<int> &v, bool flag)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        v.push_back(root->data);
    }
    else
    {
        if (flag)
        {
            helper(root->left, level - 1, v, flag);
            helper(root->right, level - 1, v, flag);
        }
        else
        {
            helper(root->right, level - 1, v, flag);
            helper(root->left, level - 1, v, flag);
        }
    }
}
// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> xx;
    bool f = false;//initially false so that in the next iteration it goes from left to right
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        helper(root, i, xx, f);
        f = !f; // palti maarne ke liye
    }
    return xx;
    // Your code here
}

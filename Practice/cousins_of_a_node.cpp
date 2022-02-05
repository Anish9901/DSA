// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
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

Node *pointer(Node *root, int n)
{
	if (root == NULL)
		return NULL;

	if (root->data == n)
		return root;

	Node *l = pointer(root->left, n);
	if (l != NULL && l->data == n)
		return l;

	Node *r = pointer(root->right, n);
	return r;
}

// } Driver Code Ends
// User function Template for C++

/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
public:
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
	vector<int> printCousins(Node *root, Node *node_to_find)
	{
		int h = height(root);
		queue<Node *> st;
		vector<int> res;
		bool flag = false;
		if(root->data == node_to_find->data)
		{
			res.push_back(-1);
			return res;
		}
		for (int i = 1; i < h; i++)
		{
			levelorderqueue(root, node_to_find, i, st, flag);
			if (flag)
			{
				while (!st.empty())
				{
					if (st.front()->left != NULL && st.front()->left->data == node_to_find->data)
					{
						st.pop();
					}
					else if (st.front()->right != NULL && st.front()->right->data == node_to_find->data)
					{
						st.pop();
					}
					else
					{
						if (st.front()->left != NULL)
						{
							res.push_back(st.front()->left->data);
						}
						if (st.front()->right != NULL)
						{
							res.push_back(st.front()->right->data);
						}
						st.pop();
					}
				}
				if (res.empty())
				{
					res.push_back(-1);
				}
				return res;
			}
			else
			{
				while (!st.empty())
				{
					st.pop();
				}
			}
		}
		return res;
	}
	void levelorderqueue(Node *root, Node *node_to_find, int h, queue<Node *> &st, bool &f)
	{
		if (root == NULL || h <= 0)
		{
			return;
		}
		if (h == 1)
		{
			st.push(root);
			if (root->left != NULL && root->left->data == node_to_find->data)
			{
				f = true;
			}
			else if (root->right != NULL && root->right->data == node_to_find->data)
			{
				f = true;
			}
		}
		levelorderqueue(root->left, node_to_find, h - 1, st, f);
		levelorderqueue(root->right, node_to_find, h - 1, st, f);
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
		int n;
		cin >> n;
		getchar();

		string inp;
		getline(cin, inp);

		struct Node *root = buildTree(inp);

		Node *p = pointer(root, n);

		Solution ob;
		vector<int> ans = ob.printCousins(root, p);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";
	}

	return 0;
}

// } Driver Code Ends
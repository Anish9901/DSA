// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void helperdfs(vector<int> adj[], int node,vector<int> &res,int *vis)
    {
        res.push_back(node);
        vis[node] = true;
        for(auto it = adj[node].begin();it != adj[node].end();it++)
        {
            if(vis[*it] == false)
            {
                //vis[*it] = true;
                helperdfs(adj,*it,res,vis);
            }
        }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        int vis[V] = {false};
        helperdfs(adj,0,res,vis);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
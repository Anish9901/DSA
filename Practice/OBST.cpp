// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void find(int i, int j, vector<pair<int, int>> &v, vector<vector<int>> &mat)
    {
        int wt = 0;
        int min = INT_MAX;
        for(int l = j;l > i;l--)
        {
            wt += v[l].second;
        }
        for(int k = i + 1; k <= j; k++)
        {
            int check = mat[i][k - 1] + mat[k][j]; 
            if(check < min)
            {
                min = check;
            }
        }
        mat[i][j] = min + wt;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<pair<int, int>> v(n + 1, {0, 0});
        int count = n+1;
        for (int i = 1; i <= n; i++)
        {
            v[i].first = keys[i - 1];
            v[i].second = freq[i - 1];
        }
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
        for (int target = 1; target <= n; target++)
        {
            for (int j = target; j <= n; j++)
            {
                for (int i = 0; i <= n - target; i++)
                {
                    if (j - i == target)
                    {
                        find(i, j, v, mat);
                    }
                }
            }
        }
        return mat[0][n];
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        int freq[n];
        for (int i = 0; i < n; i++)
            cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
} // } Driver Code Ends
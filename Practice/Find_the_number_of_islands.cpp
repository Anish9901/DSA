// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the number of islands.
    void helper(int i, int j, int rows, int cols, vector<vector<char>> &grid, vector<vector<int>> &vis) // DFS
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }
        if (vis[i][j] == 1)
        {
            return;
        }
        if (vis[i][j] == 0)
        {
            vis[i][j] = 1;

            helper(i + 1, j, rows, cols, grid, vis);
            helper(i - 1, j, rows, cols, grid, vis);
            helper(i, j + 1, rows, cols, grid, vis);
            helper(i, j - 1, rows, cols, grid, vis);
            helper(i + 1, j + 1, rows, cols, grid, vis);
            helper(i + 1, j - 1, rows, cols, grid, vis);
            helper(i - 1, j + 1, rows, cols, grid, vis);
            helper(i - 1, j - 1, rows, cols, grid, vis);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == '1')
                {
                    helper(i, j, rows, cols, grid, vis);
                    res++;
                }
            }
        }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends
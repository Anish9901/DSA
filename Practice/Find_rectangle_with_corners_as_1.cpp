// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool ValidCorner(const vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        // int k = 1;
        for (int i = 0; i < rows - 1; i++)
        {
            for (int j = 0; j < cols - 1 ; j++)
            {
                for (int k = i + 1; k < rows; k++)
                {
                    for (int l = j + 1; l < cols; l++)
                    {
                        if (matrix[i][j] & matrix[i][l] & matrix[k][j] & matrix[k][l])
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        vector<vector<int>> matrix(row);

        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

// } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void givedir(int &lastdir, int &dir)
    {
        switch (lastdir)
        {
        case 0:
            dir = 3;
            break;
        case 1:
            dir = 2;
            break;
        case 2:
            dir = 0;
            break;
        case 3:
            dir = 1;
            break;
        default:
            break;
        }
        lastdir = dir;
    }
    pair<int, int> endPoints(vector<vector<int>> matrix)
    {
        int up = -1, right = 1, down = 1, left = -1;
        int n = matrix.size();
        int m = matrix[0].size();
        int lastdir = 0;
        int dir = 0; // 0 = right,1 = left,2 = up, 3 = down
        int i = 0, j = 0;
        pair<int, int> res;
        while (i * j <= (m - 1) * (n - 1))
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                givedir(lastdir, dir);
            }
            /* if(matrix[i][j] ==  0)
            {
                //go in same dir
            } */
            switch (dir)
            {
            case 0:
                j += right;
                break;
            case 1:
                j += left;
                break;
            case 2:
                i += up;
                break;
            case 3:
                i += down;
                break;
            default:
                break;
            }
            if (i >= n || i < 0 || j < 0 || j >= m)
            {
                if (i >= n)
                {
                    i -= 1;
                }
                else if (i < 0)
                {
                    i += 1;
                }
                else if (j < 0)
                {
                    j += 1;
                }
                else if (j >= m)
                {
                    j -= 1;
                }
                res = {i, j};
                break;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int row, col;
        scanf("%d", &row);
        scanf("%d", &col);
        vector<vector<int>> matrix(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        pair<int, int> p = obj.endPoints(matrix);

        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
} // } Driver Code Ends
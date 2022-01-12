// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> matrix;
    vector<int> result_matrix;
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix1, int r = 0, int c = 0)
    {

        matrix = matrix1;

        int rs = 0;
        int rl = r - 1;
        int cs = 0;
        int cl = c - 1;

        while (result_matrix.size() < (r * c))
        {

            funcall(rs, rl, cs, cl);

            rs++;
            cs++;
            rl--;
            cl--;
        }
        return result_matrix;
    }
    void funcall(int rs, int rl, int cs, int cl)
    {
        for (int i = cs; i <= cl; i++)
        {
            result_matrix.push_back(matrix[rs][i]);
        }
        for (int i = rs + 1; i < rl; i++)
        {
            result_matrix.push_back(matrix[i][cl]);
        }
        if (rs != rl)
        {
            for (int i = cl; i >= cs; i--)
            {
                result_matrix.push_back(matrix[rl][i]);
            }
        }
        if (cs != cl)
        {
            for (int i = rl - 1; i > rs; i--)
            {
                result_matrix.push_back(matrix[i][cs]);
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
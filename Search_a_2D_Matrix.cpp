//Integers in each row are sorted from left to right.
// THE FIRST INTEGER OF EACH ROW IS GREATER THAN THE LAST INTEGER OF THE PREVIOUS ROW
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>matrix, int target)
    {
        int x[matrix.size()];
        int si = 0, j = 0,ei = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            x[i] = matrix[i][0];
        }
        if (target > x[matrix.size() - 1])
        {
            si = matrix.size() - 1;
            ei = si + matrix[0].size();
            for (int i = si; i < ei; i++)
            {
                if (matrix[si][i] == target)
                {
                    return true;
                }
            }
            return false;

        }
        while (target >= x[j])
        {
            si = j;
            if (target == x[j])
            {
                return true;
            }
            j++;
        }

        ei = si + matrix[0].size();
        for (int i = si; i < ei; i++)
        {
            if (matrix[si][i%(matrix[0].size())] == target)
            {
                return true;
            }
        }
        return false;
    }
    
};
int main()
{
    int r, c;
    int t;
    cin >> r >> c >> t;
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
    bool result = ob.searchMatrix(matrix, t);
    cout << result << endl;
}
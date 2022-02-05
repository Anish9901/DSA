// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void prefix2d(vector<vector<int>>&pf,vector<vector<int>> &arr, int N)
    {   
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j<= N; j++)
            {
                pf[i][j] = arr[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
            }
        }
    }
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K)
    {
        int maxsum = 0;
        int lastsum = 0;
        int c,d;
        vector<vector<int>>pf(N+1,vector<int>(N+1,0));//initialise by 0
        prefix2d(pf,mat,N);
        for(int a = 1; a <= N-K+1; a++)
        {
            for(int b = 1; b <= N-K+1; b++)
            {
                lastsum = 0;
                c = a+K-1;
                d = b+K-1;
                lastsum = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
                if(lastsum > maxsum)
                {
                    maxsum = lastsum;
                }
            }
        }
        return maxsum;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> mat[i][j];
            }
        }

        int k;
        cin >> k;
        Solution obj;
        cout << obj.Maximum_Sum(mat, N, k) << "\n";
    }

    return 0;
}
// } Driver Code Ends
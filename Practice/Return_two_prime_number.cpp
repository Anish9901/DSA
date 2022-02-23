// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void seive(int N,vector<int> &s)
    {
        s[0] = 0;
        s[1] = 0;
        for (int i = 2; i <= sqrt(N); i++)
        {
            for(int j = 2; i*j <= N; j++)
            {
                s[i*j] = 0;
            }
        }
    }
    vector<int> primeDivision(int N)
    {
        vector<int> s(N + 1, 1);
        vector<int> res;
        seive(N,s);
        int l,r;
        for(int i = 2; i < N + 1; i++)
        {
            if((s[i] == 1) && (s[N - i] == 1))
            {
                l = i;
                r = N - l;
                break;
            }
        }
        res.push_back(l);
        res.push_back(r);
        return res;
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

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends
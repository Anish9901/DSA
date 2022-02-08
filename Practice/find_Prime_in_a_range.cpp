// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> primeRange(int M, int N)
    {
        /* if(M == 1 || N == 1)
        {
            //do something
        }
        vector<int>res;
        vector<int>seive(N+1,1);
        seive[0] = 0;
        seive[1] = 0;

        for(int i = 2;i<=sqrt(N);i++)
        {
            for(int j = 2;i*j<=N;j++)
            {
                seive[i*j] = 0;
            }
        }
        for(int i = M;i<=N;i++)
        {
            if(seive[i] == 1)
            {
                res.push_back(i);
            }
        }
        return res; */
        vector<int> res;
        bool isprime;
        for (int j = M; j <= N; j++)
        {
            isprime = true;
            if(j == 0 || j == 1)
            {
                continue;
            }
            for (int i = 2; i <= sqrt(j); i++)
            {
                if(j % i == 0)
                {
                    isprime = false;
                    break;
                }
            }
            if(isprime)
            {
                res.push_back(j);
            }
        }
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
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans)
            cout << u << " ";
        cout << "\n";
    }
} // } Driver Code Ends
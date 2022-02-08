// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> res;
        vector<int> seive(N + 1, 1);
        seive[0] = 0;
        seive[1] = 0;

        for (int i = 2; i <= sqrt(N); i++)
        {
            for (int j = 2; i * j <= N; j++)
            {
                seive[i * j] = 0;
            }
        }
        for (int i = 2; i <= N; i++)
        {
            if (seive[i] == 1)
            {
                res.push_back(i);
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
        int N;
        cin >> N;
        Solution ob;
        vector<int> primes = ob.sieveOfEratosthenes(N);
        for (auto prime : primes)
        {
            cout << prime << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
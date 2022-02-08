// { Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void seive_for_bits(vector<int> &seive, int maxbits)
    {
        seive[0] = 0;
        seive[1] = 0;
        for (int i = 2; i <= sqrt(maxbits); i++)
        {
            for (int j = 2; i * j <= maxbits; j++)
            {
                seive[i * j] = 0;
            }
        }
    }
    int primeSetBits(int L, int R)
    {
        if (L > R)
        {
            return 0;
        }
        int maxbits = floor(log2(R)) + 1;
        int copy, ans = 0;
        int arr[R - L + 1] = {0};
        vector<int> res(maxbits + 1, 1);

        seive_for_bits(res, maxbits);

        for (int i = L; i <= R; i++)
        {
            copy = i;
            while (copy) // for counting set bits in the given range
            {
                arr[i - L] += copy & 1;
                copy >>= 1;
            }
            if (res[arr[i - L]] == 1) // for getting ans
            {
                ans++;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.primeSetBits(L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends
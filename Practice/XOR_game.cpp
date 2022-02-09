// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int xorCal(int k)
    {
        int logk = floor(log2(k))+1;
        if(k == 1)
        {
            return 2;
        }
        else if(logk > 1 && k == pow(2,logk) - 1)
        {
            return pow(2,logk-1) - 1;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        Solution ob;
        cout << ob.xorCal(k) << "\n";
    }
    return 0;
} // } Driver Code Ends
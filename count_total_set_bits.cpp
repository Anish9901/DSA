// { Driver Code Starts
// Initial Template for C++

//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int counter = 0;
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        float x = -1;
        int r = 1;
        while(x!=0)
        {
            x = (n+1)/pow(2,r);
            counter+=x*(pow(2,r)/2);
            r++;
        } 
        return counter; // Your logic here
    }
    
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends
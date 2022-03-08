// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        vector<long long>v(26,0);
        for(int i = 0; i < S.length(); i++)
        {
            v[S[i] - 97] += 1;
        }
        long long n = S.length();
        long long res = ((n)*(n - 1))/2;
        bool m = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] > 1)
            {
                long long k = (v[i]*(v[i] - 1))/2;
                m = true;
                res -= k; 
            }
        }
        if(m)
        {
            return res + 1;
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}
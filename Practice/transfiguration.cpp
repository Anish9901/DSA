//time 88m 49s

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	int a[26] = {0};
        int n = A.length() -1 ,m = B.length() -1 ;
        int res = 0;
        if(A.length() != B.length())
        {
            return -1;
        }
        for(int i = 0 ; i < A.length(); i++)
        {
            a[toupper(A[i]) - 'A']++;
            a[toupper(B[i]) - 'A']--;
        }
        for(int i = 0 ;i<26;i++)
        {
            if(a[i] != 0)
            {
                return -1;
            }
        }
        while(n >= 0)
        {
            if(A[n] != B[m])
            {
                n--;
                res++;
                continue;
            }
            n--;
            m--;
        }
        return res;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends
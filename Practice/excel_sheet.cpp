//timebyme 43m 10s
//Avg time 30m

// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string res;
        int rem = 0,quotiont = 0;
        quotiont = N/26;
        rem = N % 26;
        if(rem == 0 && quotiont != 0)//for getting Z.
        {
            quotiont--;
            rem = 26;
        }
        if(quotiont > 26)
        {
            res = ExcelColumn(quotiont);
        }
        if(quotiont > 0 && quotiont <= 26)
        {
            res += (quotiont - 1) + 'A';
        }
        if(rem > 0)
        {
            res += (rem-1) + 'A';
        }

        return res;
        // Your code goes here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> increasingNumbers(int N)
    {
        int arr[N] = {0};
        vector<int> r1 ;
        if(N>=2)
        {
            for(int i = pow(10,N-1);i < pow(10,N);i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }

        // Write Your Code here
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
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        /* for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl; */
        
    }
    return 0;
}  // } Driver Code Ends
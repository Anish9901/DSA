// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int countJmp = 0,i = 0,last_i = 0;
        map<int, int> m;
        for(int i = 0;i<n;i++)
        {
            m.insert(pair<int, int>(i,arr[i]));
        }
        
        while(i<n)
        {
            if(arr[i]>0 )
            {
                i+=arr[i];
                countJmp++;
            }
            if(i==n-1 && arr[0]!= arr[n-1])
            {
                countJmp--;
            }
            if(arr[i]<=0 && i<=n-1)
            {
                return -1;
            }
        }
        return countJmp;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
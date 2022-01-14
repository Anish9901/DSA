// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        multimap<int, int> mp;
        multimap<int, int>::iterator itr;
        vector<int>v;
        int x = 0;
        for(int i = 0 ; i<n;i++)
        {
            mp.insert({arr1[i],0});
            
        }
        for(int i = 0; i<m;i++)
        {
            mp.insert({arr2[i],0});
        }
        for(itr = mp.begin();itr!=mp.end();++itr)
        {
            v.push_back(itr->first);
        }
        /* BELOW METHOD NOT WORKING IN GFG BUT WORKING LOCALLY */
        /* int i = 0;
        int j = 0;
        
        vector<int>arr;
        for(int p = 0; p<n+m;p++)
        {
            int x1 = arr1[i],x2 = arr2[j];
            if(x1<=x2)
            {
                arr.push_back(x1);
                i++;
            }
            else if(x2<x1)
            {
                arr.push_back(x2);
                j++;
            }
        }
        /* for(int p = 0; p<n+m;p++)
        {
            cout<<arr[p]<<" ";
        } 
        //cout<<endl;
        int x = k-1;
        return arr[x]; */
        return v[k-1];
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends
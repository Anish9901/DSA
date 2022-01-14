//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int count0 = 0 ,count1 = 0,count2= 0;
        for(int i = 0; i< n;i++)
        {
            if(a[i]==0)
            {
                count0++;
                
            }
            if(a[i]==1)
            {
                count1++;
                
            }
            if(a[i]==2)
            {
                count2++;
                
            }
        }
        int i = 0;
        while (count0--)
        {
            a[i]=0;
            i++;
        }
        while (count1--)
        {
            a[i]=1;
            i++;
        }
        while (count2--)
        {
            a[i]=2;
            i++;
        }
        
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
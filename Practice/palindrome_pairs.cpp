// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    string reverse_string(string a,int n)
    {
        string g = "";
        for(int i = n-1;i>=0;i--)
        {
            g = g + a[i];
        }
        return g;
    }
    // Function to check if a palindrome pair exists

    bool palindromepair(int N, string arr[])
    {
        bool ans = 0;
        string arr2[N*(N-1)];
        string an = "";
        int x = 0;
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(i!=j)
                {
                    arr2[x] = arr[i] + arr[j];
                    x++;
                }
            }
        }
        for(int i = 0;i<(N*(N-1));i++)
        {
            an = reverse_string(arr2[i],arr2[i].length());
            if(arr2[i] == an)
            {
                return 1;
            }
        }
        return 0;
    }
};
// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
}
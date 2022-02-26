// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int lcs(vector<vector<int>> &v,string str1,string str2,int i , int j)
    {
        if(v[i][j] != -1)
        {
            return v[i][j];
        }
        if(str1[i] == '\0'||str2[j] == '\0')
        {
            v[i][j] = 0;
            return v[i][j];
        }
        if(str1[i] == str2[j])
        {
            v[i][j] = 1 + lcs(v,str1,str2,i+1,j+1);
            return v[i][j];
        }
        else
        {
            int a = lcs(v,str1,str2,i+1,j);
            int b = lcs(v,str1,str2,i,j+1);
            v[i][j] = max(a,b);
            return v[i][j];
        }

    }
    int build_bridges(string str1, string str2)
    {
        vector<vector<int>>v(str1.length() + 1,vector<int>(str2.length() + 1, -1));//memorization
        return lcs(v,str1,str2,0,0);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        int i = 0,j = 0,n = s1.length();

        while(i<n && j<n)
        {
            if(s1[i] == '#')
            {
                i++;
                continue;
            }
            if(s2[j] == '#')
            {
                j++;
                continue;
            }
            if(s1[i] != s2[j] || s1[i] == 'B' && i > j || s1[i] == 'A' && i < j)//because B cannot go left once i > j and A cannot go right once i < j
            {
                return "No";
            }
            i++;
            j++;
        }   
        while(i < n)
        {
            if(s1[i] != '#')
            {
                return "No";
            }
            i++;
        }
        while(j<n)
        {
            if(s2[j] != '#')
            {
                return "No";
            }
            j++;
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
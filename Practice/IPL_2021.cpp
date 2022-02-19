// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) 
    {
        stack<pair<char,int>>st;
        int a = 0,b = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i],i});
            }
            if(!st.empty() && s[i] == ')')
            {
                a += 2;
                st.pop();
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
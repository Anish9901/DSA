// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    {
        string str = "";
        string result = "";
        stack<string> st;
        int i = 0;
        while(i<S.length())
        {
            if(S[i] == '.'||S[i] == '\n')
            {
                st.push(str);
                st.push(".");
                str = "";
                i++;
                continue;
            }
            else
            {
                str+=S[i];
                i++;
            }
        }
        if(!str.empty())
        {
            st.push(str);
        }
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        return result;
        // code here 
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
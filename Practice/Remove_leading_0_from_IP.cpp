// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string res = "",sub = "";
        for(int i = 0; i<=s.length();i++)
        {
            if(sub == "" && s[i] == '0')
            {
                continue;
            }
            else if(s[i] == '.')
            {
                if(sub == "")
                {
                    res+= '0';
                }
                else
                {
                    res += sub;
                    sub = "";
                }
                res += '.';
            }
            else if(s[i] == '\0')
            {
                if(sub == "")
                {
                    res += '0';
                }
                else
                {
                    res+=sub;
                }
            }
            else
            {
                sub += s[i];
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends
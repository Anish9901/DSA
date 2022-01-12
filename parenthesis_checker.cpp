// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        int counter = 0;
        if ((x.length()) % 2 != 0)
        {
            return false;
        }
        for(int i= 0;i<x.length();i++)
        {
            if (x[i] == '[' || x[i] == '{' || x[i] == '(')
            {
                s.push(x[i]);
                counter++;
            }
            else if (!s.empty() && ((s.top() == '(' && x[i] == ')') || (s.top() == '[' && x[i] == ']') || (s.top() == '{' && x[i] == '}')))//check for stack emptyness also
            {
                s.pop();
                counter++;
            }

            else
            {
                return false;
            }
        } 
        if (counter == x.length() && s.empty())
        {
            return true;
        }

        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends
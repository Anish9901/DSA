// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length() == s2.length())
        {    queue<char>v1,v2;
            for(int i = 0;i<s1.length();i++)
            {
                v1.push(s1[i]);
            }
            for(int i = 0;i<s2.length();i++)
            {
                v2.push(s2[i]);
            }
            for(int i = 0; i< s1.length();i++)
            {
                char x = v1.front();
                v1.pop();
                v1.push(x);
                if(v1 == v2)
                {
                    return 1;
                }
            }
            
            /* cout<<"v1"<<"\tv2"<<endl;//debug
            for(int i = 0;i<s1.length();i++)
            {
                cout<<v1.front()<<"\t"<<v2.front()<<endl;
                v1.pop();
                v2.pop();
            }
            cout<<endl; */
        }
        else
        {
            return 0;
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
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends
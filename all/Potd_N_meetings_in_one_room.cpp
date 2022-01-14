// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        multimap<int, int> m;
        multimap<int, int>::iterator itr;
        int count_meetings =1;
        int f,s;
        
        for (int i = 0; i < n; i++)
        {
            m.insert({end[i], start[i]});
        }
        itr = m.begin();
        f=itr->first;
        s=itr->second;
        /* for (itr = m.begin(); itr != m.end(); ++itr)
        {
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';
        } */
        do
        {
            ++itr;
            if(itr->second>f && itr->second>s)
            {
                f = itr->first;
                s = itr->second; 
                count_meetings++;
            }


        } while (itr!=m.end());
        
        return count_meetings;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends
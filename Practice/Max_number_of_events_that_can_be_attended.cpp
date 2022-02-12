#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    /* static bool comparator(pair<int,int> i1,pair<int,int> i2)
    {
        if(i1.second == i2.second)
        {
            return i1.first < i2.first;
        }
        else
        {
            return i1.second < i2.second;
        }
    } */
    int maxEvents(int start[], int end[], int N) {
        if(N == 1)
        {
            return 1;
        }
        vector<pair<int,int>>v;
        /* set<int> s;
        queue<int> q;
        map<int,int> mp; */
        
        for(int i = 0;i<N;i++)
        {
            v.push_back({start[i],end[i]});
            /* if(end[i] > max)
            {
                max = end[i];
            } */
        }
        /* for(int i = 1;i<=max;i++)
        {
            s.insert(i);
            //q.push(i);
        } */
        sort(v.begin(),v.end());
        /* for(int i = 0;i< N;i++)
        {
            if(q.empty())
            {
                break;
            }
            if(q.front() <= v[i].second && q.front() >= v[i].first)
            {
                res++;
            }
            q.pop();
        } */
        /* for(int i = 0;i< N;i++)
        {
            if(s.empty())
            {
                break;
            }
            auto it = s.lower_bound(v[i].first);
            if( *it <= v[i].second)
            {
                res++;
                s.erase(it);
            }
        } */
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = 0;
        int d = 0,res = 0;//d is the pool of days {1,2,3,4,5,6}
        while(!pq.empty()||i<N)
        {
            if(pq.size() == 0)
            {
                d = v[i].first;
            }
            while(i<N && v[i].first <= d)
            {
                pq.push(v[i++].second);
            }
            pq.pop();
            res++;
            d++;
            while(!pq.empty() && pq.top() < d)
            {
                pq.pop();
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
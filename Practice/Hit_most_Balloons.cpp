// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/* !!!!!!!!!!!!!!!!!!!!!!MY SOLUTION GIVING TLE !!!!!!!!!!!!!!!!! */
class Solution
{
public:
    void helper(pair<int,int> arr[],int l,int r,int &count)
    {
        if (r - l + 1 < 2 || r <= l)
        {
            return;
        }
        double x1, x2, y1, y2,a,b;
        int cp = 0;
        x1 = arr[l].first;
        x2 = arr[r].first;
        y1 = arr[l].second;
        y2 = arr[r].second;
        a = x2 - x1;
        b = y2 - y1;
        double m = b/a, c = y1 - (m*x1);
        double mk;
        for (int i = l; i <= r; i++)
        {
            mk = b * arr[i].first + c * a;
            if (arr[i].second*a == mk || arr[i].second == m * arr[i].first + c)
            {
                cp++;
            }
        }
        if(cp > count)
        {
            count = cp;
        }
        helper(arr,l,r - 1,count);
        helper(arr,l + 1,r,count);
    }
    int mostBalloons(int N, pair<int, int> arr[])
    {
        int count = 0;
        helper(arr,0,N - 1,count);
        return count;
    }
};
/* EDITORIAL */
/* class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
       int ans = 0;
       for(int i = 0; i < N; i++){
           int x1 = arr[i].first;
           int y1 = arr[i].second;
           
           int cnt = 0;
           
           unordered_map<double,int> mp;
           
           for(int j = 0; j < N; j++){
               int x2 = arr[j].first;
               int y2 = arr[j].second;
               
               if(x2 == x1 && y2 == y1){
                   cnt++;
                   continue;
               }
               else{
                   double slope = (double)(y2-y1) / (double)(x2-x1);
                   mp[slope]++;
               }
           }
           
           for(auto p: mp){
               ans = max(ans,p.second+cnt);
           }
       }
       
       return (ans);
   }
}; */
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
} // } Driver Code Ends
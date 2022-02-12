#include <bits/stdc++.h>
using namespace std;

int ans(vector<int> &v, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(v[i] == i)
        {
            
        }
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N,res;
        cin>>N;
        int arr[N];
        vector<int>v(N+1,0);
        for(int i = 0; i < N; i++)
        {
            cin>>arr[i];
            v[i+1] = arr[i];
            //v.push_back(arr[i]);
        }
        res = ans(v,N);
        cout<<res<<endl;
    }
}
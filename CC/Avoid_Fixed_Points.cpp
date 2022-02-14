#include <bits/stdc++.h>
using namespace std;

void addele(int pos,int val,vector<int> &v)
{
    v.insert(v.begin()+pos,val);
}
int ans(vector<int> &v, int n)
{
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(v[i] == i)
        {
            addele(i,v[i]+1,v);
            res++;
            n++;
        }
    }
    return res;
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
        vector<int>v(N+1,-1);
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
#include <bits/stdc++.h>
using namespace std;
/* long long solve(long long l, long long r)
{
    //vector<pair<int, bool>> v;
    long long count = 0,div = r - l + 1;
    for (int i = l; i <= r; i++)
    {
        v.push_back({i, false});
    }
    for(long long i = 1; div*i<=r; i++)
    {
        if(div*i >= l)
        {
            count++;
        }
    }
    return count;
} */
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        long long l, r, d;
        cin >> l >> r;
        d=r-l+1;
	    cout<<r/d-l/d<<'\n';
    }
}
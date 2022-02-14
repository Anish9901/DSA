#include <bits/stdc++.h>
using namespace std;
bool inversions(vector<int> &v,int pos)
{
    for(int i = pos; i < v.size() - 1;i++)
    {
        if (v[pos] > v[i + 1] && (v[pos]&v[i+1]) != 0)
        {
            return 1;
        }

    }
    return 0;
}
bool solve(vector<int> &v, int N)
{

    /* vector<pair<int,int>> vr;
    for(int i = 0; i< v.size();i++)
    {
        vr.push_back({v[i],i});
    } */
    int x = 1,min = 1;
    bool y;
    for (int i = 1; i < v.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[i] && (v[i] & v[j]) != 0)
            {
                min = j;
            }
            //if()
        }
        if(v[min] != v[i])
        {
            swap(v[min], v[i]);
        }
        y = inversions(v,i);
        if(y)
        {
            i--;
        }
    }

    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            return 0;
        }
    }
   
    return 1;
    // sort(vr.begin(),vr.end());
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N;
        bool res;
        cin >> N;
        int arr[N];
        vector<int> v(N + 1, -1);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            v[i + 1] = arr[i];
        }
        res = solve(v, N);
        if (res)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
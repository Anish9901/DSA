// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct triple
    {
        int bits, values, index;
    };
    /* static bool compareInterval(triple i1, triple i2)
    {
        if (i1.bits == i2.bits)
        {
            return (i1.index < i2.index);
        }
        return (i1.bits > i2.bits);
    } */
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return a.first > b.first;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>>res(n,{0,0});
        for (int i = 0; i < n; i++)
        {
            res[i].second = arr[i];
            //res[i].index = i;
            while (arr[i])
            {
                res[i].first += arr[i] & 1;
                arr[i] >>= 1;
            }
        } 
        /* vector<triple> res(n, {0, 0, 0});
        for (int i = 0; i < n; i++)
        {
            res[i].values = arr[i];
            res[i].index = i;
            while (arr[i])
            {
                res[i].bits += arr[i] & 1;
                arr[i] >>= 1;
            }
        } */
        stable_sort(res.begin(),res.end(), comp);
        //sort(res.begin(), res.end(), compareInterval);
        /* cout << "Values"
             << "\tbits"
             << "\tindex\n";
        for (int i = 0; i < n; i++)
        {
            cout << res[i].second << "\t" << res[i].first << "\t" << "NULL"<<"\n";
        } */
        /* for(int i = 0;i<n;i++)
        {
            arr[i] = res[i].values;
        } */
        for(int i = 0;i<n;i++)
        {
            arr[i] = res[i].second;
        }
        
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
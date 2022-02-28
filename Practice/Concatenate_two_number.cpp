// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long countPairs(int N, int X, vector<int> numbers)
    {
        int res = 0;
        string a = "", b = to_string(X);
        map<string, int> mp;
        for (int i = 0; i < numbers.size(); i++)
        {
            mp[to_string(numbers[i])]++;
        }
        vector<pair<string, string>> v;
        string s = "";
        for (int i = b.length() - 1; i > 0; i--) 
        {
            string temp = "";
            temp += b[i];
            s.insert(0, temp);
            b.pop_back();
            v.push_back({b, s});
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == v[i].second && mp[v[i].first] >= 2)
            {
                res += mp[v[i].first]*(mp[v[i].first] - 1);
            }
            else if (mp[v[i].first] >= 1 && mp[v[i].second] >= 1 && v[i].first != v[i].second)
            {
                res += mp[v[i].first]*mp[v[i].second];
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N >> X;
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout << ans << endl;
    }

    return 0;
} // } Driver Code Ends
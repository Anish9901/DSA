#include <bits/stdc++.h>
using namespace std;
int solver(string s,int prize)
{
    int c = 0,n = 0;
    for(int i = 0; i< 14;i++)
    {
        if(toupper(s[i]) == 'C')
        {
            c++;
        }
        else if(toupper(s[i]) == 'N')
        {
            n++;
        }
        /* else if(toupper(s[i]) == 'D')
        {
            d++;
        } */
    }
    if(c > n)
    {
        return 60*prize;
    }
    else if(n > c)
    {
        return 40*prize;
    }
    else if(c == n)
    {
        return 55*prize;
    }
    return 0;
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int res,prize;
        string ip;
        cin >> prize >> ip;
        res = solver(ip,prize);
        cout << res << endl;
    }
}
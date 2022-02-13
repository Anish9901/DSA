#include <bits/stdc++.h>
using namespace std;

bool ans(string s,int n)
{
    /* if (s.length() == 1 || s.length() == 2)
    {
        return 1;
    } */
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            c1++;
        }
        else if (s[i] == '0')
        {
            c0++;
        }
    }
    if (n % 2 == 0)   
    {
        if (c1 % 2 == 0 && c0 % 2 == 0)
        {
            return 1;
        }
        else if(c1 == c0)//imp case 111000 c1 = 3, c0 = 3 (c1 % 2 == 0 && c0 % 2 == 0) false and (c1 % 2 == 0 || c0 % 2 == 0) false
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else//for odd n,1 ya 0 me se kuch toh even ho hi jayega. 
    {
        return 1;
    }
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
        string s;
        cin >> s;
        res = ans(s,N);
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
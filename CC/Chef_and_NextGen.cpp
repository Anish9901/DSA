#include<bits/stdc++.h>
using namespace std;
string solver(int A, int B, int X, int Y)
{
    if(X*Y >= A*B)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
    return "NO";
}
int main()
{
    int t = 0,A,B,X,Y;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>X>>Y;
        string res = solver(A,B,X,Y);
        cout << res << endl;
    }
}
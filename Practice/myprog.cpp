#include <bits/stdc++.h>
using namespace std;
int main()
{
    int currstreak, currpts, days = 0,div = 0;
    cout << "Your curr points: ";
    cin >> currpts;
    //cout << endl;
    int target = 400;
    cout << "Your current streak: ";
    cin >> currstreak;
    //cout << endl;
    div = currstreak % 8;
    currpts = currpts - div;
    int i = currpts;
    while (i < target)
    {
        if (days % 8 == 0 && days != 0)
        {
            days++;
            i += 9;
        }
        else
        {
            i++;
            days++;
        }
    }
    cout << "Days: " << days<<endl;
}
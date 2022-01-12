// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void shuffleArray(int arr[], int n)
    {
        int a[n / 2], b[n / 2];
        int x = 0;
        int y = 1;
        for (int i = 0; i < (n / 2); i++)
        {
            a[i] = arr[i];
            b[i] = arr[i + (n / 2)];
        }
        for (int i = 0; i < (n / 2); i++)
        {
            arr[x] = a[i];
            x += 2;
            arr[y] = b[i];
            y += 2;
        }

        // Your code goes here
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.shuffleArray(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
    return 0;
} // } Driver Code Ends
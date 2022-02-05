// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int x,y;
        if(N == 0)
        {
            return -1;
        }
        else if(N%2 == 0|| N == 1)
        {
            x = log2(N);
            y = pow(2,x);
            if(y == N)
            {
                return x + 1;
            }
        }
        else
        {
            return -1;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
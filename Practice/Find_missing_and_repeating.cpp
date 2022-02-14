// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        static int res[2];
        int a2[n+1] = {0};
        for(int i = 0;i<n;i++)
        {   
            a2[arr[i]]++;
        }
        for(int i = 1; i<= n;i++ )
        {
            if(a2[i] == 0)
            {
                res[1] = i;
            }
            else if(a2[i] == 2)
            {
                res[0] = i;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
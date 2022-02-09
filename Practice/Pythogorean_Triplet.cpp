// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    if(n<3)
        {
            return false;
        }
        int a = 0,b = 0,c = 0;
        map<int,bool> mp;
        for(int i = 0;i<n;i++)
        {
            arr[i] = arr[i]*arr[i];
            mp.insert({arr[i],true});
        }
        //sort(arr,arr + n);
        int sum = 0;
        for(int i = 0; i< n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                sum = arr[i]+arr[j];
                if(mp[sum] == true)
                {
                    return true;
                }
                /* for(int k = j + 1;k < n;k++)
                {
                    if(sum == arr[k])
                    {
                        return true;
                    }
                } */
            }
        }
        return false;
        /* int i = 0,j = i + 1, k = n - 1;
        while(j > i && j < k)
        {
            a = arr[i];
            b = arr[j];
            c = arr[k];
            if(a*a + b*b == c*c)
            {
                return true;
            }
            j++;
        } */
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
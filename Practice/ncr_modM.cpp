// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int nCr(long long n, long long r) {
    if(r > n)
    {
        return 0;
    }
    long long varn = 0;
    long long vard = 0;
    long long numerator = 1;
    long long denominator = 1;
    //long long result = 0;
    if(n-r > r)
    {
        varn = n - r; 
        vard = r;
    }
    else
    {
        varn = r;
        vard = n - r;
    }
    if(vard% 1000003 > varn% 1000003)
    {
        return 0;
    }
    for(long long i = n; i > varn; i--)
    {
        numerator *= i;
    }
    for(long long i = vard; i > 1; i--)
    {
        denominator *= i;
    }
    return (numerator/denominator) % 1000003;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long n, r;
		cin >> n >> r;
		Solution obj;
		int ans = obj.nCr(n, r);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
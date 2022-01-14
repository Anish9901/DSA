// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
            int arr[26];
            string res ="";
            for(int i = 0;i<A.length();i++)
            {
                arr[A[i]-'a']++;
            }
		    queue<char>q;
            char c = '#';
            int x = 0;
            for(int i = 0;i<A.length();i++)
            {
                q.push(A[i]);
            }
            for(int i = 0;i<A.length();i++)
            {
                c = q.front();
                arr[c-'a']++;
                if(arr[c-'a']==1)
                {
                    res+=c;
                }
                /* else 
                {
                    res+='#';
                } */
            }

		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
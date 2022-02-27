// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // 0 1 2 3 4
        // 0 1 2 1 2
        int ans = INT_MAX;
        int arr[3] = {0};
        int j = 0;
        for(int i = 0;i < S.length(); i++)
        {
            if(S[i] == '0')
            {
                arr[0]+=1;
            }
            else if(S[i] == '1')
            {
                arr[1]+=1;
            }
            else if(S[i] == '2')
            {
                arr[2]+=1;
            }
            if(arr[0]*arr[1]*arr[2]>0)
            {
                ans = min(ans,i - j + 1);
                arr[S[j] - '0'] -= 1;
                j++;
            }
            while(j < i && arr[0]*arr[1]*arr[2] > 0)
            {
                ans = min(ans,i - j + 1);
                arr[S[j] - '0'] -= 1;
                j++;
            }
        } 
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
/* EDITORIAL SOLUTION */
/* class Solution {
  public:
    int smallestSubstring(string S) {
        bool answerExist = false;
        int lastZero = -1, lastOne = -1, lastTwo = -1;
        int ans = S.size();
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') {
                lastZero = i;
            } else if (S[i] == '1') {
                lastOne = i;
            } else {
                lastTwo = i;
            }

            if (lastZero != -1 && lastOne != -1 && lastTwo != -1) {
                answerExist = true;
                ans = min(ans, 1 + i - min(lastZero, min(lastOne, lastTwo)));
            }
        }
        if (answerExist) {
            return ans;
        }
        return -1;
    }
}; */
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends
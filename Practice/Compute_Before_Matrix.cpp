//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        vector<vector<int>> pf(N+1,vector<int>(M+1,0));
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                pf[i][j] = after[i - 1][j - 1];
            }
        }
        vector<vector<int>>res(N,vector<int>(M));
        
        //pf[i][j] = arr[i][j] + pf[i-1][j] +pf[i][j -1] - pf[i-1][j-1]
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M ;j++)
            {
                res[i - 1][j - 1] =  pf[i][j] - pf[i -1][j] - pf[i][j-1] + pf[i - 1][j - 1];
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends
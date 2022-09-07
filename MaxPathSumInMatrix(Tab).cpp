//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int n,vector<vector<int>> &mat){
        //base case
        //if(j<0 || j>=n) return -1e5;
        if(i==n-1) return mat[i][j];
        
        int val = mat[i][j];
        int s,ld,rd;
        s = ld = rd = -1e8;
        if(j-1>=0)ld = f(i+1,j-1,n,mat);
        s = f(i+1,j,n,mat);
        if(j+1<n)rd = f(i+1,j+1,n,mat);
        
        int maxi = max(ld,max(s,rd));
        return (val + maxi);
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        /*int ans = 0;
        for(int col=0; col<n; col++){
            //largest sum that can be travelled while starting from
            //ith col in 0th row till last row
            int val = f(0,col,n,mat);
            ans = max(ans,val);
        }
        return ans;
        */
        
        int dp[n][n];
        
        //base case
        for(int j=0; j<n; j++) dp[n-1][j] = mat[n-1][j];
        
        //0->n-1 n-1->0
        for(int i=n-2; i>=0 ;i--){
            for(int j=0; j<n; j++){
                
                int s,ld,rd;
                s = ld = rd = -1e8;
                s = mat[i][j] + dp[i+1][j];
                if(j-1>=0)ld = mat[i][j] + dp[i+1][j-1];
                if(j+1<n)rd = mat[i][j] + dp[i+1][j+1];
                
                dp[i][j] = max(ld,max(s,rd));
            }
        }
        
        
        int ans = dp[0][0];
        for(int j=1; j<n; j++){
            ans = max(ans,dp[0][j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

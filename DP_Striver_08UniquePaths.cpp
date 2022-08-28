#include <bits/stdc++.h>
int solve(int i,int j,int m,int n){
    //base case
    if(i<0 || j<0 || i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1){
        return 1;
    }
    
    int right = solve(i,j+1,m,n);
    int down = solve(i+1,j,m,n);
    return right+down;
}
int memoized(int i,int j,int m,int n,vector<vector<int>> &dp){
    //base case
    if(i<0 || j<0 || i>=m || j>=n) return 0;
    if(i==0 && j==0){
        return dp[i][j] = 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int left = memoized(i,j-1,m,n,dp);
    int up = memoized(i-1,j,m,n,dp);
    dp[i][j] = (right+down);
    return dp[i][j];
}
int uniquePaths(int m, int n) {
    //vector<vector<int>> dp(m,vector<int>(n,-1));
	//return memoized(0,0,m,n,dp);
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    //base case
    dp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) continue;
            int left = dp[i][j-1];
            int up = dp[i-1][j];
            dp[i][j] = (right+down);
            return dp[i][j];
        }
    }
    return dp[m-1][n-1];
}

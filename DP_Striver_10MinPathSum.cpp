#include<bits/stdc++.h>
int mod = 1e9;
int solve(int i,int j,vector<vector<int>> &grid){
    if(i==0 && j==0)return grid[0][0];
    if(i<0 || j<0) return mod;
    
    int up = grid[i][j] + solve(i-1,j,grid);
    int left = grid[i][j] + solve(i,j-1,grid);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    //return solve(n-1,m-1,grid);
    
    int dp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0)
               dp[0][0] = grid[0][0];
            else{
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up = 1e9;

                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left = 1e9;

                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

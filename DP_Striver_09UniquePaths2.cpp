long long int solve(int i,int j,vector< vector< int> > &mat,vector<vector<int>> &dp){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0 || mat[i][j]==-1) return 0;
    if(dp[i][j]!= -1)return dp[i][j];
    
    int up = solve(i-1,j,mat,dp) % 1000000007;
    int left = solve(i,j-1,mat,dp) % 1000000007;
    dp[i][j] = (up + left) % 1000000007;
    return dp[i][j];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    //long long int ans= solve(n-1,m-1,mat,dp);
    //return (ans % 1000000007);
    
    //tabulation
    
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(mat[i][j] == -1)dp[i][j] = 0;
           else if(i==0 && j==0)dp[i][j] = 1;
           else{
               int up=0 , left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];
                dp[i][j] = (up + left) % 1000000007;
           }
       }
   }
    return dp[n-1][m-1];
}

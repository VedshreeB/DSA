int f(int i,int j,int n,vector<vector<int>>& tria,vector<vector<int>> &dp){
    if(j>i) return 1e7;
    if(i==n-1) return tria[i][j];
    if(dp[i][j] != -1)return dp[i][j];
    
    int down = tria[i][j] + f(i+1,j,n,tria,dp);
    int rdown = tria[i][j] + f(i+1,j+1,n,tria,dp);
    return dp[i][j] = min(down,rdown);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    
    //vector<vector<int>> dp(n,vector<int>(n,-1));
    //return f(0,0,n,triangle,dp);   
    
    int dp[n][n];
    //base case
    for(int j=0; j<n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            int down = triangle[i][j] + dp[i+1][j];
            int rdown = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,rdown);
        }
    }
    return dp[0][0];
    
}

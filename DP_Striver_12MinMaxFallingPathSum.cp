int f(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp){
    if(j<0 || j>=a[0].size()) return -1e8;
    if(i==0) return a[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    
    int s = a[i][j] + f(i-1,j,a,dp);
    int ld = a[i][j] + f(i-1,j-1,a,dp);
    int rd = a[i][j] + f(i-1,j+1,a,dp);
    return dp[i][j] = max(s,max(ld,rd));    
}
int getMaxPathSum(vector<vector<int>> &a)
{
    
    int n = a.size();
    int m = a[0].size();
    /*vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = -1e8;
    for(int j=0; j<m ; j++){
       maxi = max(maxi,f(n-1,j,a,dp));
    }
    return maxi;
    */
    
    int dp[n][m];
    
    for(int j=0; j<m; j++){
        dp[0][j] = a[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int s,ld,rd;
            s = ld = rd = -1e8;
            if(i>0) 
            {
                s = a[i][j] + dp[i-1][j];
                if(j-1>=0) ld = a[i][j] + dp[i-1][j-1];
                if(j+1<m)rd = a[i][j] + dp[i-1][j+1];
            }
            dp[i][j] = max(s,max(ld,rd));
        }
    }
    int maxi = -1e8;
    for(int j=0; j<m ; j++){
       maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
        //  Write your code here.
}

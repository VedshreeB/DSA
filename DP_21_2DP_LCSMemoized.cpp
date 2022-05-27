class Solution {
public:
    int LCS(string x, string y, int n ,int m,vector<vector<int>> &dp){
        //base case
        if(n < 0 || m < 0 )
            return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(x[n] == y[m])
            return dp[n][m] =  1 + LCS(x,y,n-1,m-1,dp);
        
        else 
            return dp[n][m] = max(LCS(x,y,n,m-1,dp), LCS(x,y,n-1,m,dp));        
    }
    int longestCommonSubsequence(string x, string y) {
    //striver
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
                
        return LCS(x,y,n-1,m-1,dp);
    }
};

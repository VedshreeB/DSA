class Solution {
public:
    
    int LCS(string x, string y, int n ,int m,vector<vector<int>> &dp){
        //base case
        if(n == 0 || m == 0 )   //empty string
            return 0;   
        
        if(dp[n-1][m-1] != -1) return dp[n-1][m-1];
        
        if(x[n-1] == y[m-1])
            return dp[n-1][m-1] =  1 + LCS(x,y,n-1,m-1,dp);
        
        else 
            return dp[n-1][m-1] = max(LCS(x,y,n,m-1,dp), LCS(x,y,n-1,m,dp));        
    }
    int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
         
        return LCS(x,y,n,m,dp);
        
    }
};

class Solution {
public:
    
 
    int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         
        /*
        no need bcoz already filled with 0
        for(int i=0; i<=n ; i++)
            dp[i][0] = 0;
        
        for(int j=0; j<=m ; j++)
            dp[0][j] = 0;*/
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ;j<=m ; j++ )
            {
                if(x[i-1] == y[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);      
            }
        }        
        
        return dp[n][m];
        
    }
};
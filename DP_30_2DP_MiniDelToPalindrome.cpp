
int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
                 
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
    int longestPalindromeSubseq(string s) {
          string rev = string(s.rbegin(), s.rend());
            
            return longestCommonSubsequence(s,rev);
    }
    int minDeletions(string str, int n) { 
    //complete the function here 
        return n  - longestPalindromeSubseq(str);
    } 

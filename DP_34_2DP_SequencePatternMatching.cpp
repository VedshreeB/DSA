Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).




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
    bool isSubsequence(string s, string t) {
        int lcs =  longestCommonSubsequence(s,t);
        if(lcs < s.length())
            return false;
        else
            return true;
    }
};

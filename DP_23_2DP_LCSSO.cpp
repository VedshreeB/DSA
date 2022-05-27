class Solution {
public:
    
 
    int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         vector<int> prev(m+1,0) , cur(m+1,0);
        /*for(int i=0; i<=n ; i++)
            dp[i][0] = 0;
        
        for(int j=0; j<=m ; j++)
            dp[0][j] = 0;*/
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ;j<=m ; j++ )
            {
                if(x[i-1] == y[j-1])
                    cur[j] =  1 + prev[j-1];
                else
                    cur[j] = max(cur[j-1], prev[j]);      
            }
            prev = cur;
        }        
        
        return cur[m];
        
    }
};

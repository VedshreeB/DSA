//IMPORTANT RULE - 
//Recur top-left to bottom-right
//Tab bottom-right to top-left but changes occur only in 
//1.base case(bottom-right)  2.return dp[0][0](top-left)

class Solution {
public:
    int RecurSolve(int i,int j, int r, int c,vector<vector<int>> &dp){
        if(i==(r-1) && j==(c-1)) return 1;

        if(dp[i][j]!= -1) return dp[i][j];
        
        int right = 0,down = 0;
        if((j+1) < c)
            right = RecurSolve(i,j+1,r,c,dp);
        if((i+1) < r)
            down = RecurSolve(i+1,j,r,c,dp);

        return dp[i][j] = (right+down);
    }
    
    int tab(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));

        //base case
        dp[m-1][n-1] = 1;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0 ; j--){
                if(i==m-1 && j==n-1) continue;

                int right = 0,down = 0;
                if((j+1) < n)
                    right = dp[i][j+1];
                if((i+1) < m)
                    down = dp[i+1][j];

                dp[i][j] = (right+down);
               
            }
        }
        return dp[0][0];
    }
    
    int uniquePaths(int m, int n) {
        //top-left to bottom-right
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        
        //return RecurSolve(0,0,m,n,dp);
        return tab(m,n);
    }
};
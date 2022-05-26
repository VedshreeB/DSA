class Solution {
public:
    int change(int T, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<long>> dp(n,vector<long>(T + 1, 0));
        
        //ind->0
        //base case
        for(int i=0; i<=T ; i++){
            dp[0][i] = (i % coins[0] == 0);
        }
        
        for(int ind=1; ind<n; ind++){
            for(int j= 0 ; j<=T ; j++){
                
                long notTake = dp[ind -1][j];
                long take = 0;
                if(coins[ind] <= j) take = dp[ind][j-coins[ind]];

                dp[ind][j] = notTake + take;
            }
        }
        
        return dp[n-1][T];       
      
    }
};

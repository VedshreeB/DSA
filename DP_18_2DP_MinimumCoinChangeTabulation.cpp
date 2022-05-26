int minimumElements(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1,0));
        
        for(int T=0 ; T<=target ; T++)
        {
              if(T % coins[0] == 0) 
                  dp[0][T] =  T/coins[0];
              else
                  dp[0][T] = 1e9;
        }
        
       for(int i=1; i<n ; i++)
       {
           for(int T=0 ; T<=target ; T++){
               int notTake = 0 + dp[i-1][T];
               int take = INT_MAX;
               if(coins[i] <=T) 
                  take = 1+dp[i][T-coins[i]];
               
               dp[i][T] = min(notTake,take);
           }
       }
        
        
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }

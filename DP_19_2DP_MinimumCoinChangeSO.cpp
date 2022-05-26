//dp[ind - 1] -> prev , dp[ind]->curr
 int minimumElements(vector<int>& coins, int target) {
        int n = coins.size();
        //vector<vector<int>> dp(n, vector<int>(target+1,0));
        vector<int> prev(target+1,0) ,curr(target+1,0);
     
        for(int T=0 ; T<=target ; T++)
        {
              if(T % coins[0] == 0) 
                 prev[T] =  T/coins[0];
              else
                  prev[T] = 1e9;
        }
        
       for(int i=1; i<n ; i++)
       {
           for(int T=0 ; T<=target ; T++){
               int notTake = 0 + prev[T];
               int take = INT_MAX;
               if(coins[i] <=T) 
                  take = 1+curr[T-coins[i]];
               
               curr[T] = min(notTake,take);
           }
           prev = curr;
       }
        
        
        int ans = prev[target];
        if(ans >= 1e9) return -1;
        return ans;
    }

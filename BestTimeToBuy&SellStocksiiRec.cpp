class Solution {
public:
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>> &dp){
       //base case
        if(ind == prices.size()-1){
            if(buy == 1)return prices[ind];
            else return 0;
        }
        
        if(dp[ind][buy]!= -1)return dp[ind][buy];
        
        if(buy == 0){
            int buying = -prices[ind] + f(ind+1,1,prices,dp);
            int noaction = f(ind+1,buy,prices,dp);
            return dp[ind][buy] = max(buying ,noaction);
        }else{
            int selling = prices[ind] + f(ind+1,0,prices,dp);
            int noaction = f(ind+1,buy,prices,dp);
            return dp[ind][buy] = max(selling,noaction);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n,vector<int>(2,-1));
        //return f(0,0,prices,dp);/
        
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        dp[n-1][1] = prices[n-1];
        dp[n-1][0] = 0;
        
        for(int ind=n-2; ind>=0 ; ind--){
            for(int buy = 0; buy<2; buy++){
                
              if(buy == 0){
                    int buying = -prices[ind] + dp[ind+1][1];
                    int noaction = dp[ind+1][buy];
                    dp[ind][buy] = max(buying ,noaction);
                }else{
                    int selling = prices[ind] + dp[ind+1][0];
                    int noaction = dp[ind+1][buy];
                    dp[ind][buy] = max(selling,noaction);
                }
            }
        }
        return dp[0][0];
    }
};

//T.C = O(n*2)
//S.C = O(n*2)

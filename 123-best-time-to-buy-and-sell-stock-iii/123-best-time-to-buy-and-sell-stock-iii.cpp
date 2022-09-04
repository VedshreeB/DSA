class Solution {
public:
   int f(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>> &dp){
       //base case
       if(ind==prices.size()||cap == 0)return 0;
        
       if(dp[ind][buy][cap]!= -1) return dp[ind][buy][cap];
       
        if(buy == 0){
            int buying = -prices[ind] + f(ind+1,1,cap,prices,dp);
            int noaction = f(ind+1,0,cap,prices,dp);
            return dp[ind][buy][cap] = max(buying,noaction);
        }else{
            int selling = prices[ind] + f(ind+1,0,cap-1,prices,dp);
            int noaction = f(ind+1,1,cap,prices,dp);
            return dp[ind][buy][cap] = max(selling,noaction);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    
                    if(buy == 0) //we can buy
                    {
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][1][cap], dp[i+1][0][cap]);
                    }
                    if(buy==1)//we can sell
                    {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][0][cap-1],dp[i+1][1][cap]);
                    }
                }
            }
        }
        return dp[0][0][2];
        
    }
};
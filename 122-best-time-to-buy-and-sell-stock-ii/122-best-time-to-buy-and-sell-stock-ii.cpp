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
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};
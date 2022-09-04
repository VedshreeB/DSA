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
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,2,prices,dp);       
        
    }
};

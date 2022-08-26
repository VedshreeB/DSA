class Solution {
public:
    int solve1(vector<int> cost,int n){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        return (cost[n] + min(solve1(cost,n-1),solve1(cost,n-2)));
    }
    int solve2(vector<int> &cost,int n,vector<int> &dp){
        if(n==0)
            return dp[0] = cost[0];
        if(n==1)
            return dp[1] = cost[1];
        
        if(dp[n] != -1)return dp[n];        
        
        return dp[n] = (cost[n] + min(solve2(cost,n-1,dp),solve2(cost,n-2,dp)));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        //STEP 1
        vector<int> dp(n+1,-1);
        int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return ans;
    }
};
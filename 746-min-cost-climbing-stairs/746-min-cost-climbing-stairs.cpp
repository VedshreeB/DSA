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
    
    //bottom up - tabualtion
    int solve3(vector<int> &cost,int n){
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        //2,3,4,5 - n-1
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        //inital call dekho
        return min(dp[n-1],dp[n-2]);        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        /*
        //STEP 1
        vector<int> dp(n+1,-1);
        int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return ans;
        */
        
        return solve3(cost,cost.size());
        
    }
};
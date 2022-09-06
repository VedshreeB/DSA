class Solution {
public:
    int solve(int ind,int prev_ind,vector<int> &nums,vector<vector<int>> &dp){
        //base case
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int nottake = solve(ind+1,prev_ind,nums,dp);
        int take = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
            take = 1 + solve(ind+1,ind,nums,dp);
        
        return dp[ind][prev_ind+1] = max(nottake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int prev=n; prev>=0;prev--){
            dp[n][prev] = 0;
        
        }
        for(int i=n-1; i>=0 ; i--){
            for(int prev=n; prev>=0;prev--){
            
            int nottake = dp[i+1][prev+1];
            int take = 0;
            if(prev == 0 || nums[i] > nums[prev-1])
                take = 1 + dp[i+1][i];

            dp[i][prev+1] = max(nottake,take);
            }
        }
        return dp[0][0];        
                     
        //return solve(0,-1,nums,dp);
    }
};

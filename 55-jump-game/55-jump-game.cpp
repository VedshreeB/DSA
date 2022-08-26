class Solution {
public:
    bool solve(int idx,int n,vector<int> &nums){
        if(idx == n-1) return true;
        
        for(int j=1; j<=nums[idx] && (idx+j)<n; j++){
            if(solve(idx+j,n,nums))return true;
        }
        return false;
        
    }
    bool memoized(int idx,vector<int> &nums,int dp[]){
        if(idx == nums.size()-1) return true;
        if(dp[idx] != -1) return dp[idx];
        
        for(int j=1; j<=nums[idx] && (idx+j)<nums.size(); j++){
            dp[idx] = memoized(idx+j,nums,dp);
            if(dp[idx] == 1) return true;
        }
        return dp[idx] = 0;
        
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp,-1,sizeof dp);
        return memoized(0,nums,dp);
    }
};
#include<bits/stdc++.h>

int solve(int idx,vector<int> &arr){
    if(idx == 0) return arr[0];
    if(idx < 0) return 0;
        
    int pick = arr[idx] + solve(idx-2,arr);
    int notpick = 0 + solve(idx-1,arr);
    return max(pick,notpick);    
}
int memoized(int idx,vector<int> &arr,vector<int> &dp){
    if(idx == 0) return arr[0];
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    
    int pick = arr[idx] + memoized(idx-2,arr,dp);
    int notpick = 0 + memoized(idx-1,arr,dp);
    return dp[idx] =  max(pick,notpick);    
}
int tabulation(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,0);
    dp[0] = arr[0];
    for(int i=1; i<n ; i++){
        int take = arr[i];
        if(i>1) take += dp[i-2];
        int nottake = 0 + dp[i-1];
        
        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //vector<int> dp(n,-1);
    //return solve(n-1,nums);
   // return memoized(n-1,nums,dp);
    return tabulation(nums);
}

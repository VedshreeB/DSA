class Solution{   
public:
    int solve(int idx,int target,vector<int>a, vector<vector<int>> &dp){
        if(target == 0)return 1;
        if(idx == 0){
            if(a[0] == target) dp[idx][target] = 1;
            else dp[idx][target] = 0;
            return dp[idx][target];
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int nottake = solve(idx-1,target,a,dp);
        int take = 0;
        if(target >= a[idx])
            take = solve(idx-1,target-a[idx],a,dp);
            
        dp[idx][target] = nottake || take;
        return dp[idx][target];
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       return solve(n-1,sum,arr,dp);
    }
};

//T.C = O(n*sum)
//S.C = O(n*sum) + O(n)

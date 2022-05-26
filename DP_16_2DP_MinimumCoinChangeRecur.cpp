class Solution {
public:
    int f(int ind,int target,vector<int>& coins){
        if(ind == 0){
            if(target % coins[ind] == 0) return target/coins[ind];
            return 1e9;
        }
        
        int notTake = 0 + f(ind-1, target,coins);
        int take = 1e9;
        if(coins[ind] <=target) 
            take = 1+f(ind,target-coins[ind],coins);
        
        return min(notTake,take);
    }
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        
        int ans = f(n-1,target,coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

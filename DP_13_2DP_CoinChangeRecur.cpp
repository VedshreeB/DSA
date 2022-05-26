class Solution {
public:
    int f(int ind,int target,vector<int>& coins){
        
        if(ind==0){
            return (target % coins[ind] == 0);  //coins[i]>=1
        }
        
        int nottake = f(ind-1,target,coins);
        int take = 0;
        if(coins[ind] <= target)
            take = f(ind,target-coins[ind],coins);
        
        return nottake + take;
        
    }
    int change(int target, vector<int>& coins) {
        int n = coins.size();
        int res = f(n-1,target,coins);
        return res;
    }
};

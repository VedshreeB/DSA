class Solution {
public:
    int dp[101][101];
    
    int solve(int start_rod,int end_rod,vector<int> &cuts,int left,int right){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int mincost = 1e9;
        
        for(int i=left; i<=right ; i++){
            int leftcost = solve(start_rod,cuts[i],cuts,left,i-1);
            int rightcost = solve(cuts[i],end_rod,cuts,i+1,right);
            int total = (end_rod - start_rod) + leftcost + rightcost;
            if(total < mincost) mincost = total;
        }
        return dp[left][right] = mincost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return solve(0,n,cuts,0,cuts.size()-1);
    }
};
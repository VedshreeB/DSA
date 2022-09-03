class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n = A.size();
        int ans=0,mini = A[0];
        for(int i=1; i<n; i++){
            int profit = A[i] - mini;
            ans = max(ans,profit);
            mini = min(mini,A[i]);
        }
        return ans;
    }
};
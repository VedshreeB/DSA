class Solution {
public:
    void f(int ind,int T,vector<int> &ds,vector<vector<int>> &ans, vector<int> &nums){
        //base case
        if(T == 0) {
            ans.push_back(ds);
            return;
        }
        
        if(ind == nums.size() || T<0) return;
        
        //pick
        ds.push_back(nums[ind]);
        f(ind,T-nums[ind],ds,ans,nums);
        ds.pop_back();
        
        //not pick
        f(ind+1,T,ds,ans,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,target,ds,ans,candidates);
        return ans;
    }
};
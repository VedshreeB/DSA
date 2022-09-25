class Solution {
public:
    void solve(int ind,vector<int> &v,set<vector<int>> &s,vector<int>& nums){
        //base case
        if(ind == nums.size()){
            vector<int> temp = v;
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        
        //nottake
        solve(ind+1,v,s,nums);
        //take
        v.push_back(nums[ind]);
        solve(ind+1,v,s,nums);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {        
        set<vector<int>> s;
        vector<int> v;
        solve(0,v,s,nums);
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};
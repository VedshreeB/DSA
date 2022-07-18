class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
    
        map<int,int> mpp; //value,nge
        stack<int> stk;
        for(int i=n2-1; i>=0 ; i--){
        while(!stk.empty() && stk.top()<=nums2[i]) stk.pop();
        
        if(!stk.empty()) mpp[nums2[i]]  = stk.top();
        else mpp[nums2[i]] = -1;
        stk.push(nums2[i]);
        }
        
        //form ans;
        vector<int> ans;
        for(auto it : nums1){
            ans.push_back(mpp[it]);
        }
        
        return ans;
        
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <=1) return nums.size();
        int i=0,j=i+1;
        while(j<nums.size()){
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
             
            j++;
        }
        return i+1;
    }
};
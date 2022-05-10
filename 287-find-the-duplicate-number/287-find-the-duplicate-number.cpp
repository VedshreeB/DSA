class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //slow and fast contain array nos
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);  //first collison
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        } //intersection point start of cycle
        
        return slow;       
        
    }
};
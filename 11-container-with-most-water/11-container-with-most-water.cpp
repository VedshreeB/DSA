class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int low = 0;
        int high = n-1;
        int water = 0;
    
        
        while(low<high){
            int curwater = min(height[low],height[high]) * (high-low);
            water = max(water,curwater);
            
            if(height[low] <= height[high]) low++;
            else high--;
        }
        return water;
    }
};
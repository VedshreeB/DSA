class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        int leftmax[n]; 
        int rightmax[n];
        leftmax[0] = rightmax[n-1] = 0;
        
        for(int i=1;i<n ; i++){
            if(height[i-1] > leftmax[i-1])
                leftmax[i] = height[i-1];
            else
                leftmax[i] = leftmax[i-1];
        }
        
        for(int i=n-2 ; i>=0 ; i--){
            if(height[i+1] > rightmax[i+1])
                rightmax[i] = height[i+1];
            else
                rightmax[i] = rightmax[i+1];
        }
        
        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(height[i]<leftmax[i] && height[i]<rightmax[i]){
                ans += min(leftmax[i],rightmax[i]) - height[i];
            }
        }
        
        return ans;
    }
};
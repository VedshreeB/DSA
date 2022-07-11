class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        
        int ans = 0;
        int l=0,h=n-1;
        int leftmax = 0,rightmax = 0;
        
        while(l<=h){
            if(height[l] <= height[h]){
                //water will not trap if
                if(leftmax <= height[l])
                    leftmax = height[l];
                else
                    //ans += min(leftmax,rightmax) - height[l];
                    ans += leftmax - height[l];
                
                l++;
            }
            else{
                //water will not trap
                if(rightmax <= height[h])
                    rightmax = height[h];
                else
                    //ans += min(leftmax,rightmax) - height[h];
                    ans += rightmax - height[h];
                h--;
            }
        }
        
        return ans;
    }
};
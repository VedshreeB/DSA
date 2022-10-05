class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left=0,top=0,bottom=row-1,right=col-1;
      while(left<=right && top<=bottom){
              //left to right
            for(int i=left; i<=right ; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //top to btm
            for(int i=top; i<=bottom ; i++)
                ans.push_back(matrix[i][right]);
            right--;

            //right to left
            if(top<=bottom){
            for(int i=right ; i>=left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            }

            //bottom to top
            if(left<=right){
                for(int i=bottom; i>=top ; i--){
                ans.push_back(matrix[i][left]);
                }
                left++;
            }        
      }
        return ans;
    }
};
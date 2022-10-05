class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<bool> isRow(row,false);
        vector<bool> isCol(col,false);
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col ; j++){
                if(matrix[i][j]==0){
                    isRow[i]=true;
                    isCol[j]=true;
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col ; j++){
                if(isRow[i] || isCol[j]){
                    matrix[i][j] = 0;
                }
            }
        }        
    }
};
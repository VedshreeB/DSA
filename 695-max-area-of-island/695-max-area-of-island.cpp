class Solution {
public:
    void dfs(vector<vector<int>>& grid,int &count,int i,int j,int row,int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=1)
            return;
        
        grid[i][j] = 2;
        count++; 
        
        dfs(grid,count,i-1,j,row,col);
        dfs(grid,count,i+1,j,row,col);
        dfs(grid,count,i,j+1,row,col);
        dfs(grid,count,i,j-1,row,col);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col ;j++){
                if(grid[i][j] == 1)
                {
                    int count = 0;
                    dfs(grid,count,i,j,row,col);
                    maxarea = max(maxarea,count);
                }
            }
        }
        
        return maxarea;        
    }
};
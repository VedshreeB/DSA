class Solution {
public:
    bool isValid(int i,int j,int row,int col,vector<vector<int>>& board){
        if(i<0 || j<0 || i>=row || j>=col || board[i][j] != 1)
            return false;
        return true;
    }
    void dfs(int i,int j,int row,int col,vector<vector<int>>& board){
        if(isValid(i,j,row,col,board)){
            board[i][j] = 2;
            
            dfs(i-1,j,row,col,board);
            dfs(i+1,j,row,col,board);
            dfs(i,j-1,row,col,board);
            dfs(i,j+1,row,col,board);            
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        //first row and last row
        for(int i=0; i<c ;i++){
            if(grid[0][i] == 1)
                dfs(0,i,r,c,grid);
            if(grid[r-1][i] == 1)
                dfs(r-1,i,r,c,grid);
        }
        
        //first col and last col
        for(int i=0; i<r; i++){
            if(grid[i][0] == 1)
                dfs(i,0,r,c, grid);
            if(grid[i][c-1] == 1)
                dfs(i,c-1,r,c,grid);
        }
        
        int count = 0;
        for(int i=0; i<r; i++){
            for(int j=0 ;j<c ;j++){
                if(grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
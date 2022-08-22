class Solution {
public:
    bool isValid(int i,int j,int row,int col,vector<vector<int>>& board){
        if(i<0 || j<0 || i>=row || j>=col || board[i][j] != 0)
            return false;
        return true;
    }
    void DFS(int i,int j,int row,int col,vector<vector<int>>& board){
        if(isValid(i,j,row,col,board)){
            board[i][j] = 2;
            
            DFS(i-1,j,row,col,board);
            DFS(i+1,j,row,col,board);
            DFS(i,j-1,row,col,board);
            DFS(i,j+1,row,col,board);            
        }
    }
    int closedIsland(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        //row
        for(int i=0; i<col; i++){
            if(board[0][i] == 0)
                DFS(0,i,row,col,board);
            if(board[row-1][i] == 0)
                DFS(row-1,i,row,col,board);
        }
        
        //first col and last col
        for(int j=0; j<row; j++){
            if(board[j][0] == 0)
                DFS(j,0,row,col,board);
            if(board[j][col-1] == 0)
                DFS(j,col-1,row,col,board);
        }
        
        int ans =0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col ;j++){
                if(board[i][j] == 0){
                    ans++;
                    DFS(i,j,row,col,board);
                }
            }
        }
        return ans;        
    }
};
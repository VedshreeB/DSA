class Solution {
public:
    void convert(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'B')
                    board[i][j] = 'O';
            }
        }
    }
    bool isValid(int i,int j,int row,int col,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=row || j>=col || board[i][j] != 'O')
            return false;
        return true;
    }
    void DFS(int i,int j,int row,int col,vector<vector<char>>& board){
        if(isValid(i,j,row,col,board)){
            board[i][j] = 'B';
            
            DFS(i-1,j,row,col,board);
            DFS(i+1,j,row,col,board);
            DFS(i,j-1,row,col,board);
            DFS(i,j+1,row,col,board);            
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        //row
        for(int i=0; i<col; i++){
            if(board[0][i] == 'O')
                DFS(0,i,row,col,board);
            if(board[row-1][i] == 'O')
                DFS(row-1,i,row,col,board);
        }
        
        //first col and last col
        for(int j=0; j<row; j++){
            if(board[j][0] == 'O')
                DFS(j,0,row,col,board);
            if(board[j][col-1] == 'O')
                DFS(j,col-1,row,col,board);
        }
        
        convert(board);
    }
};
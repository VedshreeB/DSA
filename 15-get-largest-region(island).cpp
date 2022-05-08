Problem Description https://www.interviewbit.com/problems/region-in-binarymatrix/

Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.
 
 Problem Constraints
 1 <= N, M <= 102

 A[i][j]=0 or A[i][j]=1

Input Format
First argument is a 2D binary matrix Aof size  N x M.

Output Format
Return a single interger denoting the length of largest region.

Example Input
Input 1:

 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
Input 2:

 A = [  [1, 1, 1]
        [0, 0, 1]
    ]


Example Output
Output 1:

 6
Output 2:

 4
 
 


Example Explanation
Explanation 1:

 The largest region is denoted by red color in the matrix:
    00110
    10110
    01000
    00001
Explanation 2:

 The largest region is:
    111
    001
    
Solution Approach
Idea is based on the problem finding number of islands in Boolean 2D-matrix.Just perform dfs from each unvisited one and count the number of ones which can be visited from here and maintain the maximum.
Just perform dfs from each unvisited one and count the number of ones which can be visited from here and maintain the maximum.

A cell in 2D matrix can be connected to at most 8 neighbors. So in DFS, we make recursive calls for 8 neighbors. We keep track of the visited 1’s in every DFS and update maximum length region.
Time complexity: O(N x M)
    
 void dfs(int i,int j,vector<vector<int> > &A,int &ans){
    if(i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j] != 1)
        return;

    ans++;
    A[i][j] = 2;

    dfs(i-1,j-1,A,ans);
    dfs(i-1,j,A,ans);
    dfs(i-1,j+1,A,ans);
    dfs(i,j-1,A,ans);
    dfs(i,j+1,A,ans);
    dfs(i+1,j-1,A,ans);
    dfs(i+1,j,A,ans);
    dfs(i+1,j+1,A,ans);
}
int Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();

    int maxans = 0;

    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++){

            //dfs
            int ans = 0;
            if(A[i][j] !=0)
                dfs(i,j,A,ans);

            maxans = max(ans,maxans);    
        }

    }
    return maxans;
}

    
    
    
    



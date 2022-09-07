//{ Driver Code Starts
// Initial Template for C++
//t.c = O(n^3)
//s.c = O(n)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int n,vector<vector<int>> &mat){
        //base case
        if(j<0 || j>=n) return -1e5;
        if(i==n-1) return mat[i][j];
        
        int val = mat[i][j];
        int leftdiag = f(i+1,j-1,n,mat);
        int down = f(i+1,j,n,mat);
        int rightdiag = f(i+1,j+1,n,mat);
        
        int maxi = max(leftdiag,max(down,rightdiag));
        return (val + maxi);
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        int ans = 0;
        for(int col=0; col<n; col++){
            //largest sum that can be travelled while starting from
            //ith col in 0th row till last row
            int val = f(0,col,n,mat);
            ans = max(ans,val);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

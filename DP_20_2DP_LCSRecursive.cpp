class Solution {
public:
    int LCS(string x, string y, int n ,int m){
        //base case
        if(n < 0 || m < 0 )
            return 0;
        
        if(x[n] == y[m])
            return 1 + LCS(x,y,n-1,m-1);
        
        else 
            return max(LCS(x,y,n,m-1), LCS(x,y,n-1,m));        
    }
    int longestCommonSubsequence(string x, string y) {
    //striver
        int n = x.length();
        int m = y.length();
        
        return LCS(x,y,n-1,m-1);
    }
};

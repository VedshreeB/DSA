#include <bits/stdc++.h>
using namespace std;
void PrintlongestCommonSubsequence(string &x, string &y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ;j<=m ; j++ )
            {
                if(x[i-1] == y[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);      
            }
        }        
        
        int len  =  dp[n][m];
        string lcs;
        for(int i=0 ; i<len ; i++)
            lcs += "$";
        int index = len-1;
        int i=n , j=m;
        
        while(i>0 && j>0){
            if(x[i-1] == y[j-1]){
                lcs[index] = x[i-1];
                i--;j--;
                index--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else
                j--;
        }
        
        //print the string
        cout<<"LCS is :"<<lcs<<endl;
    
}
int main(){
    string x = "abcdgh";
    string y = "abedfr";
    
    PrintlongestCommonSubsequence(x,y);
    return 0;
    
}

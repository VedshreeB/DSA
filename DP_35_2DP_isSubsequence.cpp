//check a is a subsequence of b and vice versa if yes: return true else false
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         
        /*
        no need bcoz already filled with 0
        for(int i=0; i<=n ; i++)
            dp[i][0] = 0;
        
        for(int j=0; j<=m ; j++)
            dp[0][j] = 0;*/
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ;j<=m ; j++ )
            {
                if(x[i-1] == y[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);      
            }
        }        
        
        return dp[n][m];
        
    }
    bool isSubsequence(string s, string t) {
        int lcs =  longestCommonSubsequence(s,t);
        int n = s.length();
        int m = t.length();
        if(lcs == min(m,n))   //difference
            return true;
        else
            return false;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string a,b;
		cin >> a;
		cin>>b;
		Solution obj;
		int ans = obj.isSubsequence(a,b);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

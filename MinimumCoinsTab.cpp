//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,0));
	    
	    for(int i=0; i<=V ; i++){
	        if(i %coins[0] == 0) dp[0][i] = i/coins[0];
	        else dp[0][i] = 1e7;
	    }
	    for(int i=0; i<=M; i++){
	        dp[i][0] = 0;
	    }
	    
	    for(int i=1; i<=M ; i++){
	        for(int j=1; j<=V; j++){
	            int nottake = 0 + dp[i-1][j];
        	    int take = 0;
        	    if(coins[i-1] <= j) take = 1 + dp[i][j-coins[i-1]];
        	    else take = 1e7;
        	    dp[i][j] = min(take,nottake);
	        }
	    }
	    
	    if( dp[M][V] == 1e7) return -1;
	    else return dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends

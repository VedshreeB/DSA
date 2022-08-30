//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int ind,int coins[],int V){
	    //base case
	    if(ind == 0){
	        if(V % coins[0] == 0) return V/coins[0];
	        return 1e7;
	    }
	    
	    int nottake = 0 + solve(ind-1,coins,V);
	    int take = 0;
	    if(coins[ind] <= V) take = 1 + solve(ind,coins,V-coins[ind]);
	    else take = 1e7;
	    return min(take,nottake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    int ans = solve(M-1,coins,V);
	    if(ans == 1e7)return -1;
	    return ans;
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

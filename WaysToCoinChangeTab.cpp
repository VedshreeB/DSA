//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int ind,int sum,int coins[],vector<vector<long long int>> &dp){
        if(ind == -1){
            if(sum != 0) return 0;
            if(sum == 0) return 1;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        long long int nottake = solve(ind-1,sum,coins,dp);
        long long int take = 0;
        if(coins[ind] <= sum) take = solve(ind,sum-coins[ind],coins,dp);
        return dp[ind][sum] = (take + nottake);
    }
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,0));
        
        for(int i=0 ; i<=sum ; i++)
            dp[0][i] = 0;
            
        for(int i=0 ; i<=N; i++) dp[i][0] = 1;
        
        for(int i=1; i<=N ; i++){
            for(int j=1; j<=sum ;j++){
                long long int nottake = dp[i-1][j];
                long long int take = 0;
                if(coins[i-1] <= j) take = dp[i][j-coins[i-1]];
                dp[i][j] = (take + nottake);
            }
        }
        
        
        return dp[N][sum];
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends

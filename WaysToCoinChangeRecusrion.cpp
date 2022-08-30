//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int ind,int sum,int coins[]){
        if(ind == -1){
            if(sum != 0) return 0;
            if(sum == 0) return 1;
        }
        long long int nottake = solve(ind-1,sum,coins);
        long long int take = 0;
        if(coins[ind] <= sum) take = solve(ind,sum-coins[ind],coins);
        return (take + nottake);
    }
    long long int count(int coins[], int N, int sum) {
        
        int dp[N][sum+1];
        memset(dp,-1,sizeof dp);
        
        return solve(N-1,sum,coins,dp);
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

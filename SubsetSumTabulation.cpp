//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int idx,int target,vector<int>a, vector<vector<int>> &dp){
        if(target == 0)return 1;
        if(idx == 0){
            if(a[0] == target) dp[idx][target] = 1;
            else dp[idx][target] = 0;
            return dp[idx][target];
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int nottake = solve(idx-1,target,a,dp);
        int take = 0;
        if(target >= a[idx])
            take = solve(idx-1,target-a[idx],a,dp);
            
        dp[idx][target] = nottake || take;
        return dp[idx][target];
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,0));
       
       for(int i=0; i<n; i++) dp[i][0] = 1;
       
        dp[0][arr[0]] = 1;
       
       for(int i=1; i<n; i++){
           for(int j=1; j<=sum ; j++){
            
            int nottake = dp[i-1][j];
            int take = 0;
            if(j >= arr[i])
                take = dp[i-1][j-arr[i]];
                
            dp[i][j] = nottake || take;

           }
       }
       
        return dp[n-1][sum];
    }
};

//T.C = O(n*sum)
//S.C = O(n*sum)

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

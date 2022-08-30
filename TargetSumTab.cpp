//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
   #include<bits/stdc++.h>
int mod = 1000000007;
int solve(int ind,int tar,vector<int> &num,vector<vector<int>> &dp){
    //if(tar == 0) return 1;
    if(ind == 0){
          if(tar==0 && num[ind]==0) return 2;
          if(tar==0 || tar == num[0]) return 1;
          return 0;
    }
    if(dp[ind][tar] != -1) return dp[ind][tar];
    
    int nottake = solve(ind-1,tar,num,dp);
    int take = 0;
    if(num[ind] <= tar) 
        take = solve(ind-1,tar-num[ind],num,dp);
    
    return dp[ind][tar] = (take + nottake) % mod;
}
int findWays(vector<int> &arr, int sum)
{
       int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       return solve(n-1,sum,arr,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(auto it:arr) totsum += it;

    if(totsum-d<0 || (totsum - d)%2) return false;
    return findWays(arr,(totsum-d)/2);    
}


    int findTargetSumWays(vector<int>&A ,int target) {
        int n= A.size();
    
       return countPartitions(n,target,A);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends

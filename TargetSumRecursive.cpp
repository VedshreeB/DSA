//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int ind,int sum,int tar,vector<int> &A){
        if(ind == -1){
            if(sum == tar) return 1;
            else return 0;
        }
        
        int plus = solve(ind-1,sum + A[ind],tar,A);
        int minus  = solve(ind-1,sum - A[ind],tar,A);
        return (plus+minus);
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        int n= A.size();
        return solve(n-1,0,target,A);
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

//T.C = O(2^n)
//s.c = O(M)
// } Driver Code Ends

//T.C = O(n*n)
//S.C = O(n*n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long f(int start,int end,int n,int a[],vector<vector<int>> &dp){
        //base case
        if(start > end) return -1e8;
        if(start == end) return a[start];
        if(start+1 == end) return(a[start] > a[end]? a[start]:a[end]);
        
        if(dp[start][end] != -1) return dp[start][end];
        
        long long startsum = a[start] + min(f(start+2,end,n,a,dp),f(start+1,end-1,n,a,dp));
        long long endsum = a[end] + min(f(start+1,end-1,n,a,dp),f(start,end-2,n,a,dp));
        
        return dp[start][end] = max(startsum,endsum);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long f(int start,int end,int n,int a[],vector<vector<int>> &dp){
        //base case
        //if(start > end) return -1e8;
        if(start == end) return a[start];
        if(start+1 == end) return(a[start] > a[end]? a[start]:a[end]);
        
        if(dp[start][end] != -1) return dp[start][end];
        
        long long startsum = a[start] + min(f(start+2,end,n,a,dp),f(start+1,end-1,n,a,dp));
        long long endsum = a[end] + min(f(start+1,end-1,n,a,dp),f(start,end-2,n,a,dp));
        
        return dp[start][end] = max(startsum,endsum);
    }
    long long maximumAmount(int arr[], int n){
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        //return f(0,n-1,n,arr,dp);
        
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        for(int i=0; i<n; i++){
            dp[i][i] = arr[i];
        }
        for(int i=0; i<n-1 ; i++)
            dp[i][i+1] = arr[i]>arr[i+1]?arr[i]:arr[i+1];
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) dp[i][j] = arr[i];
                else if(i+1 == j && i<n-1) 
                    dp[i][j] = arr[i]>arr[j]?arr[i]:arr[i+1];
                else{
                    long long startsum,endsum;
                    startsum = arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                    endsum = arr[j] + min(dp[i+1][j-1],dp[i][j-2]);
                    
                    dp[i][j] = max(startsum,endsum);
                }
            }
        }
        return dp[0][n-1];
        
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

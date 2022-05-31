// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int f(int n,int x,int y, int z){
        if(n == 0) return 0;
        if(n<0) return -1e9;
        int a = f(n-x,x,y,z);
        int b = f(n-y,x,y,z);
        int c = f(n-z,x,y,z);
        return 1 + max(max(a,b),c);
    }
        
        
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1);
        
        dp[0] = 0;
        int a,b,c;
        a=b=c= -1e9;
        for(int i=1; i<=n; i++){
            
            if(i-x >=0)  a = dp[i-x];
            if(i-y >=0) b= dp[i-y];
            if(i-z>=0) c = dp[i-z];
            
            dp[i] = 1 + max(max(a,b),c);
        }
        
        if(dp[n] < 0) return 0;
        return dp[n];
        
        //Your code here
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
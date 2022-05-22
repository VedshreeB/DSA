/ { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
int perfectSum(int arr[], int n, int sum)
	{
	    long int t[n+1][sum+1];     //for bigger numbers
	    memset(t,0,sizeof t);
	    long int d = 1e9+7;
	    //initialization
	    t[0][0] = 1;
	        
	    for(int j=1 ; j<sum+1 ; j++)
	        t[0][j] = 0;
	       
	    
	    for(int i=1 ; i<n+1 ; i++){
	        for(int j=0 ; j<sum+1 ; j++){
	            
	            if(arr[i-1] <=j)
	                t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]]) % d;     //to limit the size of answers stored in t[][] to int
	            
	            else 
	                t[i][j] = t[i-1][j];
	        }
	    }
	    //unsigned long long int d = 1e9+7;
	    //int ans = t[n][sum] % d;
	    return t[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

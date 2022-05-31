// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
   
    long long countWays(int n, int k){
        // code here
        if(n == 0 && k==0) return 0;
        int M = 1e9+7;
        //if n =1 
        long long diff = k, same = 0, total = (diff + same)%M;
        
        for(int i=2 ; i<=n ; i++){
            same = diff;
            diff = (total *(k-1) ) % M;
            total = (same + diff)%M;
        }
        
        return total;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
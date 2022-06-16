// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int l=0;
	    int h = n-1;
	    
	    while(l<=h){
	        int mid = l+(h-l)/2;
	        int next = (mid+1)%n;
	        int prev = (mid+n-1)%n;
	        
	        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev] ) 
	        return mid;
	        
	        if(arr[mid]<=arr[h])
	            h = mid-1;
	        else l = mid+1;
	    }
	    
	    return 0;
}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
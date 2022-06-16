// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	   if(n<=1) return 0;
	   int l= 0;
	   int h=n-1;
	   
	   while(l<=h){
	       int mid = l + (h-l)/2;
	       
	       if(mid<h && arr[mid]>arr[mid+1])return mid+1;
	       
	       if(mid>l && arr[mid-1]>arr[mid]) return mid;
	       
	       if(arr[mid]<arr[h])  h = mid-1;
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
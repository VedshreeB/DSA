//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind,int len,int price[]){
        //base case
        if(ind == 0) return (price[0]*len);
        
        int nottake = solve(ind-1,len,price);
        int take = INT_MIN;
        if(len >= ind+1) take = price[ind] + solve(ind,len-(ind+1),price);
        return max(nottake , take);
    }
    int cutRod(int price[], int n) {
        return solve(n-1,n,price);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

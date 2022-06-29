// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(long long i=0 ; i<n; i++) pq.push(arr[i]); 
        
        long long ans = 0,sum;
        while(pq.size()>1){
            long long ele1 = pq.top();
            pq.pop();
            long long ele2 = pq.top();
            pq.pop();
            sum = ele1 + ele2;
            ans = ans + sum;
            pq.push(sum);
        }
        return ans;
    }
};
/* TC = O(NlogN) - insertion + 
        finding minimum - O(1) +
        O(N-1 log (N-1)) 
T.C = O(NlogN)
S.C = O(N)
        */
        


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
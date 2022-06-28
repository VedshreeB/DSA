// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void max_heapify(vector<int> &v,int i, int size){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left <size && v[left] > v[largest]) 
            largest = left;
        if(right < size && v[right] > v[largest])
            largest = right;
        
        if(largest != i){
            swap(v[largest],v[i]);
            max_heapify(v,largest,size);
        }
    }
    void deleteFromHeap(vector<int> &v, int size){
        v[0] = v[size-1];
        size--;
        max_heapify(v,0,size);
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        
        while(n>0 && m>0){
            if(a[0] >= b[0]){
                ans.push_back(a[0]);
                deleteFromHeap(a,n);
                n--;
            }
            else{
                ans.push_back(b[0]);
                deleteFromHeap(b,m);
                m--;
            }
        }
        for(int i=0; i<n ; i++){
            ans.push_back(a[i]);
        }
        for(int i=0; i<m ; i++){
            ans.push_back(b[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends
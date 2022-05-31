2
4 3
5 2 6 4
4 0
1 1 1 1
  
 Sum is : 17
Value of t[4]: 1 0 1 0 1 1 1 1 1 1 1 1 1 1 0 1 0 1 
 Values of s1 : 0 2 4 5 6 7 8 9 10 11 12 13 15 17 result = 1Sum is : 4
Value of t[4]: 1 1 1 1 1 
 Values of s1 : 0 1 2 3 4 result = 1
#include <bits/stdc++.h>

using namespace std;
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i=0; i<n ; i++)
        sum += arr[i];
    
    cout<<"Sum is : "<<sum;
        
    //int min = 0;
    //int max = sum;
    
    bool t[n+1][sum+1];
    
    
    //intialization
    for(int i=0 ; i<n+1 ; i++)
        t[i][0] = true;
    for(int j= 1 ; j<sum +1 ; j++)
        t[0][j] = false;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1 ; j++){
           bool p = t[i-1][j];
           if(arr[i-1] <= j) p = t[i-1][j-arr[i-1]];
           bool np = t[i-1][j];
           
           t[i][j] = np || p;
           
           if(arr[i-1] > j) t[i][j] = t[i-1][j];
           else t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
        }
    }
    cout<<"\nValue of t[4]: ";
    for(int i=0; i<sum+1; i++)
        cout<<t[n][i] << " ";
    
    vector<int> s1;
    for(int i=0 ; i<sum+1 ; i++)
    {
        if(t[n][i] == true)
            s1.push_back(i);
    }
    cout<<"\n Values of s1 : ";
    for(auto it:s1)
        cout<<it<<" ";
    
    int count = 0;
    for(int i=0; i<s1.size(); i++){
        int s2 = sum - s1[i];
        if(s1[i] >= s2 && d == (s1[i]-s2))
            count++;
    }
    
    return count;
}
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n,d;
        cin >> n>>d;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        	cin >> a[i];
	  
	    int res = countPartitions(n,d,a);
	    cout<<"result = "<<res;
	     
    }
    return 0;
}  // } Driver Code Ends

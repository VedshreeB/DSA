Problem Statement : Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their
sums is minimum and find the minimum difference.
  
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11  
  
Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 10^6


class Solution{

  public:

	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n ; i++)
	        sum += arr[i];
	        
	   int s = sum/2;
	   int t[n+1][s+1];
        
        //intialization
        for(int i=0; i<n+1 ; i++){
            t[i][0] = 1;
        }
        //intialization
        for(int i=1 ; i<s+1 ; i++)
            t[0][i] = 0;
        
        
        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<s+1; j++){
                
                 if(arr[i-1] <= j){
                    t[i][j] = (t[i-1][j] ||  t[i-1][j-arr[i-1]]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        vector<int> v;
        for(int i=0 ; i<=s; i++){
            if(t[n][i]==1)
                v.push_back(i);
        }
        
        int mv = INT_MAX;
        for(int i=0; i<v.size(); i++)
            mv= min(mv, sum - 2*v[i]);
        
        return mv;
	} 
};

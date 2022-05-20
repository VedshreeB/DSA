#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
	//space optimization
	vector<int> dp(n , 0);
	
	//dp[0] = 0;
	int prev1 = 0;
	int prev2 = 0;
		
	for(int i=1; i<n ; i++){
		
		
		int left = prev1 + abs(heights[i] - heights[i-1]);
		int right = INT_MAX;
		if(i > 1){
			right = prev2 + abs(heights[i] - heights[i-2]);
		}
		
		int curr = min(left,right);
		prev2 = prev1;
		prev1 = curr;
	}
	
	return prev1;
}

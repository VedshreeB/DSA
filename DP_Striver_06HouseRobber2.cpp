#include<bits/stdc++.h>

long long int tabulation(vector<long long int> &arr){
    int n = arr.size();
    vector<long long int> dp(n,0);
    dp[0] = arr[0];
    for(int i=1; i<n ; i++){
        long long int take = arr[i];
        if(i>1) take += dp[i-2];
        long long int nottake = 0 + dp[i-1];
        
        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    
    vector<long long int> temp1,temp2;
    for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(tabulation(temp1),tabulation(temp2));
}

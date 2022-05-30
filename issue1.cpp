https://practice.geeksforgeeks.org/problems/ncr1019/1#
 int nCr(int n, int r){
        //r = n-r < r ? n-r : r;
        if( n < r) return 0;
        long int d = 1e9+7;
        vector<int> dp(r+1,1);
        dp[0] = 1;
       
        for(int i=1 ; i<=r ; i++){
            long long int a = (dp[i-1] % d ) * ((n-i + 1) % d) % d;
            a /= i;
            dp[i] = a % d;
        }
        
        return dp[r];
    }

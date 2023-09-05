int SO(int m,int n){
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
  
        //base case
        //prev[n-1] = 1; not required already covered in loops below

        for(int i=m-1; i>=0; i--){
            vector<int> temp(n,0);
            for(int j=n-1; j>=0 ; j--){
                if(i==m-1 && j==n-1){
                    temp[j] = 1; continue;
                }

                int right = 0,down = 0;
                if((j+1) < n)
                    right = temp[j+1];
                if((i+1) < m)
                    down = prev[j];

                temp[j] = (right+down);
               
            }
            prev = temp;
        }
        return prev[0];
    }
    int uniquePaths(int m, int n) {
       return SO(m,n);
    }

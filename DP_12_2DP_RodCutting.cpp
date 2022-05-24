class Solution{
  public:
    int cutRod(int price[], int n) {
        int t[n+1][n+1];    //t[price[].size+1][n+1];
        
        for(int i=0; i<n+1; i++){
            t[0][i] = t[i][0] = 0;
        }
        
        for(int i=1; i<n+1 ; i++)
        {
            for(int j=1; j<n+1; j++){
                if(i > j){
                    t[i][j] = t[i-1][j];
                }
                else
                    t[i][j] = max(price[i-1] + t[i][j-i] , t[i-1][j]);
            }
        }
        
        return t[n][n];
    }
};

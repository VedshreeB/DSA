//Final DP code
int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n+1][W+1];
       
       for(int i=0 ; i<n+1 ; i++){
           for(int j=0 ; j<W+1 ; j++){
               if(i==0 || j==0){
                   t[i][j] = 0;
               }
               else if(wt[i-1] <= j){
                   t[i][j] = max(t[i-1][j] , val[i-1] + t[i-1][j-wt[i-1]]);
               }
               else
                t[i][j] = t[i-1][j];
           }
       }
       
       return t[n][W];
    }

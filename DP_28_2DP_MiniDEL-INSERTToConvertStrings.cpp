class Solution{
		

	public:
	int longestCommonSubsequence(string x, string y) {
       
        int n = x.length();
        int m = y.length();
        
        vector<int> prev(m+1,0) , cur(m+1,0);
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ;j<=m ; j++ )
            {
                if(x[i-1] == y[j-1])
                    cur[j] =  1 + prev[j-1];
                else
                    cur[j] = max(cur[j-1], prev[j]);      
            }
            prev = cur;
        }        
        
        return cur[m];
        
    }
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    return (n+m - 2*longestCommonSubsequence(str1,str2));
	} 
};

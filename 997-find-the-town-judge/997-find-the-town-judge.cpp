class Solution {
public:
    /*//in[], out[] //s.c = O(2*N)
     //directed graph ... indegree..outdegree
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        
        for(int i=0 ; i<trust.size() ; i++){
            int a = trust[i][0];
            int b = trust[i][1];
            
            in[b]++;
            out[a]++;
        }
        
        for(int i=1; i<=n; i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
        return -1;
    }*/
    /*
     indegree-outdegree = n-1;
     n-1    -  0 = n-1;
    */
    int findJudge(int n, vector<vector<int>>& trust){
         vector<int> check(n+1,0);
        
        for(int i=0 ; i<trust.size() ; i++){
            int a = trust[i][0];
            int b = trust[i][1];
            
            check[b]++;
            check[a]--;
        }
        
        for(int i=1; i<=n; i++){
            if(check[i]==n-1)
                return i;
        }
        return -1;
        
    }  
    //t.c = O(n) , sc = O(n)
};
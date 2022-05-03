class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =  isConnected.size();
        int ans = 0;
        vector<bool> vis(n,false);
        
        for(int i=0; i<n ; i++){
            if(!vis[i]){
                ans++;
                
                //bfs
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    
                    //adjacents
                    vector<int> v = isConnected[node];
                    for(int j=0 ; j<n  ; j++)
                    {
                        if(v[j]){
                            if(!vis[j]){
                                q.push(j);
                                vis[j] = true;
                            }
                        }
                    }
                        
                }
                
            }
        }
        
        return ans;
    }
};
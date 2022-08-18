class Solution {
public:
    void DFSRec(int i,vector<bool>&vis,vector<int>adj[]){
        vis[i] = true;
        vector<int> temp = adj[i];
        for(int x: temp){
            if(!vis[x]){
                DFSRec(x,vis,adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<bool> vis(n,false);
        
        //adjacency list
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
         DFSRec(src,vis,adj);
        
        return vis[dest];
    }
};
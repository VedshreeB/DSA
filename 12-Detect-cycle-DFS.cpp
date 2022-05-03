Cycle Detected

Time Complexity: O(N)

Space Complexity: O(N)

class Solution {
  public:
    bool cycledfs(int node,int prev, vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(cycledfs(it,node,adj,vis)) 
                    return true;
            }
            else if( it!=prev){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        
        for(int i=1; i<=V ; i++){
            if(!vis[i]){
                if(cycledfs(i,-1,adj,vis));
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends

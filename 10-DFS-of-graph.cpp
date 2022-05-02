class Solution {
  public:
    void dfs(int node,vector<int> &visited,vector<int> adj[], vector<int> &ans){
        ans.push_back(node);
        visited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it])
            {
                dfs(it,visited,adj,ans);
            }
        }
    }
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        
        for(int i=0 ; i<V; i++)
        {
            if(!visited[i]){
                dfs(i, visited, adj , ans);
            }
        }
        
        return ans;
    }
};

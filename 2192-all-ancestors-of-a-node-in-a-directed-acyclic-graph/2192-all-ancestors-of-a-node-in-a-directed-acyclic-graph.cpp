class Solution {
public:
       void dfs(int index , vector<int> adj[], vector<bool>& visited)
    {
        visited[index] = true;
        for(auto it : adj[index])
        {
            if(!visited[it])
                dfs(it,adj,visited);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>  ans(n);
        vector<int> adj[n];
        for(int i = 0 ; i < edges.size() ; i++)
            adj[edges[i][0]].push_back(edges[i][1]);
       
       for(int i = 0; i < n ;i++) 
       {   vector<bool> visited(n,false);
          if(!visited[i])
               dfs(i,adj,visited);
        for(int j =0 ; j < n;j++)
        {
            if(i==j) continue;
            if(visited[j])
                ans[j].push_back(i);
        }
           
       }
        return ans;
    }

};
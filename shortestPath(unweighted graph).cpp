vector<int> shortestPath(vector<int> adj[],int n){
    vector<bool> vis(n,false);
    vector<int> dist;
    queue<int> q;
    
    dist[0] = 0;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int u  = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!vis[u]){
                dist[v] = dist[u] + 1;
                vis[v] = true;
            }
        }
        return dist;
    }
}

class Solution {
public:
    bool BipartiteBfs(int src,vector<int> adj[],int colour[]){
        queue<int> q;
        q.push(src);
        colour[src]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //check for adjacents
            for(auto it: adj[node]){
                //if it is unvisited
                if(colour[it]==-1){
                    q.push(it);
                    colour[it] = !colour[node];
                }
                else if(colour[it] == colour[node])
                    return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    int colour[V];
    
	    memset(colour , -1, sizeof colour);
	    
	    for(int i=0 ; i<V; i++)
	    {
	        if(colour[i] == -1){
	            if(!BipartiteBfs(i,adj,colour))
	                return false;
	        }
	    }
	    
	    return true;
	}

};

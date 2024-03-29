//for all connected and disconnected graphs

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> visited(V,0);
        
        for(int i=0; i<V ; i++){
            if(visited[i]==0){
                //code for applying bfs on one node
                queue<int> q;
                q.push(i);
                visited[node] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                                    
                    //traverse adjacent nodes to given node
                    for(auto it : adj[node]){
                        if(visited[it] == 0){
                            q.push(it);
                            visited[node] = 1;
                        }
                    }
                }
                
            }
            
        }
        return bfs;
    }
    
};
*jab bhi queue mein push kare tab visited mark karna hai

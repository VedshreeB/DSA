
//  to find the number of connected components in the given undirected graph. 
#include <bits/stdc++.h>
using namespace std;

int countComponents(int n, vector<int> adj[]) {
    int ans= 0;
    vector<int> vis(n+1,0);
    stack<int> dfs;
        
    for(int i=1; i<=n ; i++){
        if(!vis[i]){
            ans++;
                
            //dfs
            dfs.push(i);
            vis[i]= 1;
            while(!dfs.empty())
            {
                int node = dfs.top();
                dfs.pop();
                    
                for(auto it:adj[node])
                {
                    if(!vis[it]){
                        vis[it]=1;
                        dfs.push(it);
                    }
                }
            }
                
        }
    }
    return ans;
}

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Driver code
int main()
{
    int V = 7;
    vector<int> adj[V+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 7);
    addEdge(adj, 7, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 3, 5);
    
    
    cout<<countComponents(7,adj);
    return 0;
}

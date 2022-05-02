void addEdge(vector<int> adj[nv], int u,int v){
  
  //for undirected graph
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main(){
  
  int nv = 5; //no. of vertices
  vector<int> adj[nv];
  addEdge(adj,0,1);
  addEdge(adj,1,2);
  addEdge(adj,4,3);
  addEdge(adj,2,4);
  addEdge(adj,4,5);
  
  return 0;
}

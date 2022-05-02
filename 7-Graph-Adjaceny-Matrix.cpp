int main(){
  int nv; //no. of vertices
  int ne; //no. of edges
  cin>>nv>>ne;
  
  int adj[nv+1][nv+1]; //1-based indexing
  
  //intializing by 0
  for(int i=1; i<=nv ; i++)
  {
    for(int j=1; j<=nv ; j++){
      adj[i][j]=0;
    }
  }
  
  //takes edges one by one
  for(int i=0 ; i<ne ; i++)
  {
    int u;  //starting point of edge
    int v; //ending point of edge
    cin>>u>>v;
    
    //undirected graph
    adj[u][v] = adj[v][u] = 1;
  }
  
  return 0;
}

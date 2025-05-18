import java.util.ArrayList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayDeque;

class Main {
    //implementation of graph representation as adjancency list in java
    //note vertices are numbered from 1
    //graph
    /*
    
        1 ---- 2 
        \       -
        \         - 5
        \         -        6-----7
        3 ----- 4
    */
  public static void main(String[] args) {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    //intialization
    int v=7;
    for(int i=0; i<=v ; i++ ){
        adj.add(new ArrayList<Integer>());
    }
    
    //adding an edge for undirected graph
    //edge 1---2
    adj.get(1).add(2);
    adj.get(2).add(1);
    
    //edge 1---3
    adj.get(1).add(3);
    adj.get(3).add(1);
    
    //edge 3---4
    adj.get(3).add(4);
    adj.get(4).add(3);
    
    //edge 2----5
    adj.get(2).add(5);
    adj.get(5).add(2);
    
    //edge 4---5
    adj.get(4).add(5);
    adj.get(5).add(4);
    
    //edge 6-----7
    adj.get(6).add(7);
    adj.get(7).add(6);
    
    // //adding edge for directed graph
    // //edge 1--->3
    // adj.get(1).add(3);
    
    
    // //print all edges
    // for(int i=1; i<=v ; i++)
    // {
    //     for(int u: adj.get(i)){
    //         System.out.println("edge from vertex:"+ i + " to " + u);
    //     }
    // }
    
    Main m = new Main();
    
    //bfs
    List<Integer> bfsTraversal = new ArrayList<Integer>();
    boolean visited[] = new boolean[v+1];
    for(int i=1; i<=v ; i++){
        if(!visited[i]){
            m.bfs(i,visited,adj,bfsTraversal);
        }
    }
    
    
    //printing the resulting bfs bfsTraversal
    System.out.println("BFS TRAVERSAL : ");
    for(Integer vertex : bfsTraversal){
        System.out.print( vertex + ",");
    }
  }
  
  public void bfs(int v, boolean visited[],ArrayList<ArrayList<Integer>> adj,List<Integer> bfsTraversal){
      Queue<Integer> queue = new ArrayDeque<>();
      queue.add(v);
      visited[v] = true;
      
      while(!queue.isEmpty()){
        int u = queue.remove();
        bfsTraversal.add(u);
        
        for(int adjVertex : adj.get(u)){
            if(!visited[adjVertex]){
                queue.add(adjVertex);
                visited[adjVertex]=true;
            }
        }
      }
  }
}

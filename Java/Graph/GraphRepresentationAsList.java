import java.util.ArrayList;

class Main {
    //implementation of graph representation as adjancency list in java
  public static void main(String[] args) {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    //intialization
    int v=5;
    for(int i=0; i<=v ; i++ ){
        adj.add(new ArrayList<Integer>());
    }
    
    //adding an edge for undirected graph
    //edge 1-->2
    adj.get(1).add(2);
    adj.get(2).add(1);
    
    
    //adding edge for directed graph
    //edge 1--->3
    adj.get(1).add(3);
  }
}

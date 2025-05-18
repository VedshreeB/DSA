//FIND NO OF PROVINCES OR ISLANDS
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int ans = 0;
        int n = isConnected.length;
        boolean visited[] = new boolean[n];
        for(int i=0; i<n ; i++){
            if(visited[i]==false){
                ans++;
                bfs(i,visited,isConnected);
            }
        }

        return ans;
    }

    private void bfs(int v, boolean visited[], int[][] isConnected){
        Queue<Integer> q = new LinkedList<Integer>();
        //push it
        q.add(v);
        visited[v]=true;

        while(!q.isEmpty()){
            int u = q.poll();
            //bfs.add(u);

            for(int i=0; i<isConnected.length; i++){
                if(isConnected[u][i]==1 && visited[i]==false){
                    q.add(i);
                    visited[i]=true;
                }
            }
        }
    }
}

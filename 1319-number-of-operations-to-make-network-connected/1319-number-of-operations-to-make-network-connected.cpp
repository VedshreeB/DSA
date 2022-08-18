class Solution {
public:
    //simple dfs
     void helper(unordered_map<int,vector<int>>&m,vector<int>&vis,int node){
        vis[node]=1;
        for(auto nbr:m[node]){
            if(!vis[nbr]){
                // cout<<node<<" "<<nbr<<endl;
                helper(m,vis,nbr);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        //edge case if wires are less than required
        if(edges<n-1){
            return -1;
        }
        //making graph
        unordered_map<int,vector<int>>m;
        for(int i=0;i<connections.size();i++){
            int x=connections[i][0];
            int y=connections[i][1];
            m[x].push_back(y);
            m[y].push_back(x);
        }
        //vis vector for dfs
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                helper(m,vis,i);
            }
        }
        //returning disconnected components-1
        return count-1;
    }
};
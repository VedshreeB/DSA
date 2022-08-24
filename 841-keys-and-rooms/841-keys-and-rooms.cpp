class Solution {
public:
    void DFSRec(int src,vector<bool> &vis,vector<vector<int>>& rooms,int n)     {
        vis[src] = true;
        for(int x : rooms[src]){
            if(vis[x] == false)
                DFSRec(x,vis,rooms,n);
        }        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        
        DFSRec(0,vis,rooms,n);
        
        for(int i=0; i<n; i++){
            if(vis[i] == false)
                return false;
        }
        return true;        
    }
};
class Solution {
public:
void DFSRec(int src,int n, vector<int> &path,vector<vector<int>>&ans,vector<vector<int>>& graph)
{     
        path.push_back(src);
        if(src == n-1)
            ans.push_back(path);
        else {      
            for(auto x:graph[src])
                DFSRec(x,n,path,ans,graph);
         }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> path;
        
        DFSRec(0,n,path,ans,graph);
        return ans;
    }
};
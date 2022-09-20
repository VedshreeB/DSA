class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mpp;
        
        for(auto &s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(s);
        }
        
        for(auto &a:mpp){
            ans.push_back(a.second);    
        }
        return ans;
    }
};
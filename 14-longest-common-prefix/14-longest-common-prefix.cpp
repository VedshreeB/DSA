class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minlen = INT_MAX;
        bool flag = false;
        
        for(int i=0 ; i<n ; i++){
            if(minlen > strs[i].length()) minlen = strs[i].length();
        }
        
        string ans = "";
        for(int i=0; i<minlen ; i++){
            for(int j=0 ; j<n-1 ; j++){
                if(strs[j][i] != strs[j+1][i]){
                    flag = true;
                    break;
                }
                    
            }
            if(!flag)
                ans += strs[0][i];
            else break;
        }
        return ans;
    }
};
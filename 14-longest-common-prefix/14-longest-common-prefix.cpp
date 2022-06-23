class Solution {
public:
    //WORD BY WORD
    string LCP(string s1,string s2){
        string ans = "";    //empty string
        
        int len = min(s1.length(),s2.length());
        
        for(int i=0; i<len; i++){
            if(s1[i]!=s2[i]) break;
            ans += s1[i];
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];
        for(int i=1 ; i<n ; i++)
            prefix = LCP(prefix,strs[i]);
        
        return prefix;
    }
};
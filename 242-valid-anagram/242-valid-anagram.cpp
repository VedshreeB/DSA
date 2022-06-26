class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen != tlen) return false;
        
        
        map<char,int> mpp;
        for(int i=0; i<slen; i++)
            mpp[s[i]]++;
        for(int i=0 ; i<tlen;i++)
        {
            if(mpp.find(t[i])==mpp.end())
                return false;
            else{
                mpp[t[i]]--;
                if(mpp[t[i]]==0) mpp.erase(t[i]);
            }
        }
        return true;
    }
};
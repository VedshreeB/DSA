class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int ans= 0;
        int i=s.length()-1;
        ans += mpp[s[i--]];
        while(i>=0){
            if(mpp[s[i]]<mpp[s[i+1]])
                ans -= mpp[s[i]];
            else
                ans += mpp[s[i]];
            i--;
        }
        return ans;        
    }
};
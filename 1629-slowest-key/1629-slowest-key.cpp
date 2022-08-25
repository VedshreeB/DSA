class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        int maxd = rt[0];
        char c = kp[0];
        
        for(int i=1; i<rt.size();i++){
            int val = rt[i] - rt[i-1];
            if(val > maxd){
                maxd = val;
                c = kp[i];
            }
            else if(val == maxd && kp[i] > c)
                c = kp[i];
        }
        return c;
    }
};
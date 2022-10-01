class Solution {
public:
    int solve(int i,string &s,int *dp){
        if(i>=s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        
        int ans = 0;
        int op1=s[i]-'0',op2=0;
        if(i<s.length()-1){
            op2 = op1*10 + s[i+1]-'0';
        }
        if(op1>0)ans += solve(i+1,s,dp);
        if(op1>0 && op2>0 && op2<=26) ans+=solve(i+2,s,dp);
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int dp[101];
        memset(dp,-1,sizeof dp);
        return solve(0,s,dp);
    }
};
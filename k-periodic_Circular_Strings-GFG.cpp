class Solution{
    public:
    string kPeriodic(string s, int K){
       int n = s.length();
       int block_size = __gcd(n,K);
       
       //lexicographic order that's why we used map instead of unordered map
       map<char,int> mpp;
       for(auto i : s)
        mpp[i]++;
        
        int noOfBlocks = n/block_size;
        for(auto it: mpp){
            //chars can be individually divided in each block equally
            //if not then this
            if(it.second % noOfBlocks != 0)
                return "";
        }
        
        //s+ s+ s ->ans
        //we just create 1 s(block) and add it noOfBlocks times
        string ss="";
        for(auto it : mpp){
            char c = it.first;
            
            int howManyTimes = it.second/noOfBlocks;
            while(howManyTimes --)
                ss += c;
        }
        
        string ans="";
        //add s noOfBlocks time
        for(int i=1; i<=noOfBlocks ; i++){
            ans += ss;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int K;
        cin >> K;
        Solution obj;
        string ans = obj.kPeriodic(s, K);
        if(ans.length() == 0){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}  // } Driver Code Ends

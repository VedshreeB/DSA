class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n =changed.size();
        if(n%2)return {};
        
        vector<int> original;
        sort(changed.begin(),changed.end());
        multiset<int> s;
        int cnt = 0;
        for(int i =n-1 ; i>=0; i--){
            int val = changed[i]*2;
            multiset<int>::iterator it = s.find(val);
            if(s.empty() || it == s.end()){
                s.insert(changed[i]);
            }else{
                original.push_back(changed[i]);
                s.erase(it);
                cnt++;
            }
        }
    
        if(cnt == n/2) 
            return original;
        else return {};
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string ans;
        string temp="";
        for(auto it:s){
         
            if(it == ' '){
                reverse(temp.begin(),temp.end());
                ans.append(temp);
                ans += ' ';
                temp = "";
            }
            
            else{
                temp = temp + it;
            }
        }
        
        reverse(temp.begin(),temp.end());
        ans.append(temp);
        return ans;
    }
};
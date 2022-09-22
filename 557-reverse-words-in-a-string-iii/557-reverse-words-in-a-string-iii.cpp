class Solution {
public:
    string reverseWords(string s) {
        /*int len = s.length(); //O(1)
        string ans;
        string temp="";
        for(auto it:s){
         
            if(it == ' '){
                reverse(temp.begin(),temp.end());       //O(|temp|)
                ans.append(temp);   //O(|temp|)
                ans += ' ';
                temp = "";
            }
            
            else{
                temp = temp + it;
            }
        }
        
        reverse(temp.begin(),temp.end());
        ans.append(temp);
        return ans;*/
        
        int n = s.length();
        int j=0;
        
        for(int i=0;i<=n;i++){
            if(s[i]==' '|| s[i]=='\0'){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
        }
        return s;
    }
};
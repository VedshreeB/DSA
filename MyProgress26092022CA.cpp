/*

  My Daily Progress
  990. Satisfiability of Equality Equations
  Applied constructive algorithm
  Passed 166/181 testcases
*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        map<pair<char,char>,bool> mpp;
        //bool isSame = false, isEqual = false;
        for(string s:equations){
            bool isSame = false, isEqual = false;
            char a = s[0]<s[3]?s[0]:s[3];
            char b = s[0]>s[3]?s[0]:s[3];
            if(a==b) isSame = true;
            if(s[1] == s[2]) isEqual = true;
            
            if(isSame && !isEqual) return false;
            
            if(isSame && isEqual) continue;
            
            if(mpp.find({a,b}) != mpp.end()){
                bool val = mpp[{a,b}];
                if(val != isEqual){
                    return false;
                }
            }else{
                mpp[{a,b}] = isEqual;
            }
            
        }
        return true;
    }
};

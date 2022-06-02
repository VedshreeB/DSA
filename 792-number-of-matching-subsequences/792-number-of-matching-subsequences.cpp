class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string word : words) {
            int posAtS = -1;
            for (int i = 0; i < word.length(); i++) {
                posAtS = s.find(word[i], ++posAtS);
                if (posAtS == -1) {
                    break;
                }
            }
            if (posAtS >= 0) {
                count++;
            }
        }
        return count;
    }
};
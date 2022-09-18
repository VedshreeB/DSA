class Node{
public:
    Node *child[26];
    bool isTerminal;
};

class Trie {
public:
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *p = root;
        for(int i=0; i<word.length(); i++){
            //absent
            int indx = word[i]-'a';
            if(p->child[indx] == NULL)
                p->child[indx] = new Node();
            p = p->child[indx];
        }
        p->isTerminal = true;
    }
    
    bool search(string word) {
        Node *p = root;
        for(int i=0; i<word.length() && p!=NULL; i++){
            
            //absent
            if(p->child[word[i]-'a'] == NULL)
                return false;
            p = p->child[word[i]-'a'];
        }
        return p->isTerminal;
    }
    
    bool PrefixUtil(string word) {
        Node *p = root;
        for(int i=0; i<word.length() && p!=NULL; i++){
            
            //absent
            if(p->child[word[i]-'a'] == NULL)
                return false;
            p = p->child[word[i]-'a'];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        return PrefixUtil(prefix);
    }
    
    void remove(string word){
        Node *p = root;
        for(int i=0; i<word.length() && p!=NULL; i++){
            
            //absent
            if(p->child[word[i]-'a'] == NULL)
                return;
            p = p->child[word[i]-'a'];
        }
        p->isTerminal = false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
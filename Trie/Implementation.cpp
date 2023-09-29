#include <iostream>
using namespace std;

class TrieNode{
    public: 
        TrieNode *children[26];
        bool isTerminal;
        
        TrieNode(){
            for(int i=0; i<26; i++)
                children[i]=NULL;
                
            isTerminal = false;
        }
};

class Trie{
    public: 
    TrieNode *root = NULL;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *cur = root;
        
        for(auto ch : word){
            int index = ch - 'a';
            
            //absent
            if(cur->children[index] == NULL)
                cur->children[index] = new TrieNode();
                
            cur = cur->children[index];
        }
        
        cur->isTerminal = true;
    }
    
    bool search(string word){
        TrieNode *cur = root;
        
        for(auto c : word){
            int index = c-'a';
            //absent
            if(cur->children[index]==NULL) return false;
            
            cur = cur->children[index];
        }
        
        //and and andy case
        return cur->isTerminal;
    }
    
    void remove(string word){
        
        TrieNode *cur = root;
        
        for(auto c: word){
            
            //absent
            if(cur->children[c-'a']==NULL)return;
            
            cur = cur->children[c-'a'];
        }
        cur->isTerminal = false;
    }
    
    bool startsWith(string prefix){
        TrieNode *cur = root;
        
        for(auto c : prefix){
            //absent
            if(cur->children[c-'a'] == NULL) return false;
            
            cur = cur->children[c-'a'];
        }
        return true;
    } 
};

int main() {
	Trie *obj = new Trie();
	obj->insert("and");
	obj->insert("ant");
	obj->insert("dada");
	cout<<obj->startsWith("dae")<<endl;    //0
	cout<<obj->startsWith("dada")<<endl;    //1
	
	obj->remove("and");  
	cout<<obj->search("and");    //0
	return 0;
}

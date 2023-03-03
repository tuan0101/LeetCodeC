//struct: 82% 58%
//class: 92% 40%
class TrieNode{  // has to be declaired before main class
public:
    TrieNode* next[26]; //TrieNode* next[26] = {};
    bool _isWord;    
    //TrieNode(){
       //next  = new TrieNode[26];    
    //}
};

class Trie {
    TrieNode* root;
public:    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char &c : word){
            if(node->next[c-'a']==NULL)
                node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];    // also update after create a new NODE             
        }
        node->_isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node!=NULL && node->_isWord;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != NULL;
    }
    
    TrieNode* searchPrefix(string prefix){
        TrieNode* node = root;
        for(char &c : prefix){
            if(node->next[c-'a'])
                node = node->next[c-'a'];
            else
                return NULL;
        }
        return node;
    } 
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
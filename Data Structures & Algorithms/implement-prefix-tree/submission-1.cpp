class TrieNode {
public:
    TrieNode* children[26];
    bool isleaf;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isleaf = false;
    }
};

class PrefixTree {
public:
TrieNode* root;
    PrefixTree() {
root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr= root;
        for(char c: word){
            if(curr->children[c-'a']==nullptr){
                TrieNode* root2= new TrieNode();
                curr->children[c-'a']=root2;
            }
        curr= curr->children[c-'a'];
        }
        curr->isleaf=true;
    }
    
    bool search(string word) {
        TrieNode* curr= root;
        for(char c: word){
            if(curr->children[c-'a']==nullptr)return false;
        curr= curr->children[c-'a'];
        }
        return curr->isleaf;
    }
    
    bool startsWith(string prefix) {
                TrieNode* curr= root;
        for(char c: prefix){
            if(curr->children[c-'a']==nullptr)return false;
        curr= curr->children[c-'a'];
        }
        return true;
    }
};

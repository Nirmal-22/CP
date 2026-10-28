// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {

    struct Node{
        Node* children[26];
        bool isEnd;
        Node() : isEnd(false){
            for(int i=0;i<26;i++) children[i]= nullptr;
        }
    };
    Node* root;
public:
    Trie() : root(new Node()){}
    
    void insert(string word) {
        Node* cur= root;

        for(char c: word){
            int idx = c-'a';
            if(!cur->children[idx])
                cur->children[idx] = new Node();

            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char c:word){
            int idx = c-'a';
            if(!cur->children[idx]) return false;
            cur = cur->children[idx];        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c: prefix){
            int idx = c - 'a';
            if(!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

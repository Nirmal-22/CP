// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct TrieNode{
    bool isWord = false;
    TrieNode* children[26] = {nullptr};
};

class WordDictionary {
    TrieNode* root;

    bool dfs(const string& word, int idx, TrieNode* node){
        if(!node) return false;
        if(idx == word.size()) return node->isWord;

        char c= word[idx];
        if(c == '.')
        {
            for(int i=0;i<26;i++){
                if(dfs(word, idx+1, node->children[i]))
                    return true;
            }
            return false;
        }
        else {
            return dfs(word, idx+1, node->children[c-'a']);
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c:word){
            int i= c- 'a';
            if(!cur->children[i])
                cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }

        cur->isWord = true;
    }

    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

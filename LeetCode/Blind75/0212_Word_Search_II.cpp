// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& ws) {
        struct TrieNode{
            array<TrieNode*, 26> nxt{};
            string word{};
            // ~TrieNode(){ for(auto p:nxt) if(p) delete p;}
        };

        TrieNode* root= new TrieNode();
        for(auto& w: ws){
            TrieNode* cur = root;
            for(char c:w) {
                int i= c - 'a';
                if(!cur->nxt[i]) cur->nxt[i] = new TrieNode();
                cur = cur->nxt[i];
            }
            cur->word = w;
        }

        int m = b.size(), n= b[0].size();
        vector<string> ans;
        vector<vector<char>> vis(m, vector<char>(n,0));
        function<void(int,int, TrieNode*)> dfs = [&](int x,int y, TrieNode* node){
            char ch = b[x][y];
            int idx = ch - 'a';
            node = node->nxt[idx];
            if(!node) return;
            if(!node->word.empty()) {
                ans.push_back(node->word); 
                node->word.clear();
            }
            vis[x][y] = 1;
            const int dx[4] = {1,-1,0,0}, dy[4]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny])
                    dfs(nx,ny,node);
            }
            vis[x][y] = 0;
        };

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dfs(i,j,root);
        
        // delete root;
        return ans;
    }
};

// 79. Word Search
// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& b, string w) {
        int m = b.size(), n= b[0].size();
        
        // vector<int> cb(256, 0), cw(256, 0);

        // for(auto& row: b)
        //     for(char c:row)
        //         ++cb[c];

        // for(char c:w)
        //     ++cw[c];

        // for(int i=0;i<256;i++)
        //     if(cw[i] > cb[i])
        //         return false;


        // if(cb[w.front()] > cb[w.back()])
        //     reverse(w.begin(), w.end());

        vector<vector<bool>> used(m, vector<bool>(n, false));
        
        int dir[4][2] {{1,0}, {-1,0}, {0,1}, {0,-1}};

        function<bool(int, int, int)> dfs = [&](int r, int c, int idx){
            if(idx == w.size()) return true;
            if(r<0 || r>=m || c<0 || c>=n || used[r][c] || b[r][c] != w[idx])
                return false;
            
            used[r][c] = true;
            for(auto& d: dir){
                if(dfs(r+d[0], c+d[1], idx+1)){
                    used[r][c] = false;
                    return true;
                }
            }
            used[r][c] = false;
            return false;
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j] == w[0] && dfs(i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

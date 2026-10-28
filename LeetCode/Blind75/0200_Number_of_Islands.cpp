// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        
        int n= grid[0].size(), count=0;

        function<void(int, int)> dfs = [&](int r, int c){
            if(r<0 || r>=m || c<0 || c>=n || grid[r][c] !='1')
                return;

            grid[r][c] = '0';
            dfs(r+1, c);
            dfs(r-1, c);
            dfs(r, c+1);
            dfs(r, c-1);
        };

        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    ++count;
                    dfs(i, j);
                }
            }
        }

        return count;
    }
};

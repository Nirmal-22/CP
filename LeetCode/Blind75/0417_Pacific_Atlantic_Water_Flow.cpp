// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        if(m==0) return {};
        int n= h[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int i=0; i<m; i++){
            p[i][0] = true;
            q.push({i,0});
        }

        for(int j=1; j<n; j++){
            p[0][j] = true;
            q.push({0,j});
        }

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for(auto &d: dirs){
                int nr = r+d[0], nc = c+d[1];
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                if(p[nr][nc]) continue;
                if(h[nr][nc] < h[r][c]) continue;
                p[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        for(int i=0;i<m;i++){
            a[i][n-1] = true;
            q.push({i, n-1});
        }

        for(int j=0;j<n-1;j++){
            a[m-1][j] = true;
            q.push({m-1, j});
        }

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for(auto &d: dirs){
                int nr = r+d[0], nc = c+d[1];
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                if(a[nr][nc]) continue;
                if(h[nr][nc] < h[r][c]) continue;
                a[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        vector<vector<int>> result;
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                if(p[i][j] && a[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};

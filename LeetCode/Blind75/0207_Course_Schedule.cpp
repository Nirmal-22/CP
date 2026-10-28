// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& g) {
        vector<vector<int>> adj(n);
        vector<int> id(n,0);

        for(auto& p:g){
            int c = p[0], pre = p[1];
            adj[pre].push_back(c);
            ++id[c];
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(id[i] == 0) q.push(i);
        }

        int taken =0;

        while(!q.empty()){
            int u=q.front(); q.pop();
            ++taken;
            for(int v: adj[u]){
                if(--id[v]==0){
                    q.push(v);
                }
            }
        }
        return (taken == n);
    }
};

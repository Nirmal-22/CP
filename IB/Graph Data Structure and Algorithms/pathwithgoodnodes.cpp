int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) 
{
    const int MAX_N = 100005;
        vector<vector<int>> tree(MAX_N);
        vector<int> goodNodes(MAX_N);
        int countPaths = 0;

        for (int i = 0; i < A.size(); i++) 
            goodNodes[i + 1] = A[i];
        

        for (int i = 0; i < B.size(); i++) 
        {
            int u = B[i][0];
            int v = B[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        function<void(int, int, int)> dfs = [&](int node, int parent, int goodCount) 
        {
            if (goodNodes[node] == 1) 
                goodCount++;
            // else 
            //     goodCount = 0;

            if (goodCount > C) 
                return;

            bool isLeaf = true;

            for (int child : tree[node]) 
            {
                if (child != parent) 
                {
                    isLeaf = false;
                    dfs(child, node, goodCount);
                }
            }

            if (isLeaf && goodCount <= C) 
                countPaths++;
            
        };

        dfs(1, 0, 0);

        return countPaths;
}

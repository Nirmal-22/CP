int Solution::solve(vector<vector<int> > &A) 
{
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> blueVisited(n, vector<bool>(m, false));
    vector<vector<bool>> redVisited(n, vector<bool>(m, false));

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    function<void(int, int, vector<vector<bool>>&)> dfsBlue = [&](int i, int j, vector<vector<bool>>& visited) 
    {
        visited[i][j] = true;
        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && A[ni][nj] >= A[i][j]) 
            {
                dfsBlue(ni, nj, visited);
            }
        }
    };

    function<void(int, int, vector<vector<bool>>&)> dfsRed = [&](int i, int j, vector<vector<bool>>& visited) 
    {

        visited[i][j] = true;
        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && A[ni][nj] >= A[i][j]) 
            {
                dfsRed(ni, nj, visited);
            }
        }
    };

    // DFS from the Blue lake
    for (int i = 0; i < n; ++i) 
    {
        if (!blueVisited[i][0]) 
        {
            dfsBlue(i, 0, blueVisited);
        }
    }

    for (int j = 0; j < m; ++j) 
    {
        if (!blueVisited[0][j]) 
        {
            dfsBlue(0, j, blueVisited);
        }
    }

    // DFS from the Red lake
    for (int i = 0; i < n; ++i) 
    {
        if (!redVisited[i][m - 1]) 
        {
            dfsRed(i, m - 1, redVisited);
        }
    }

    for (int j = 0; j < m; ++j) 
    {
        if (!redVisited[n - 1][j]) 
        {
            dfsRed(n - 1, j, redVisited);
        }
    }

    // Count cells visited by both lakes
    int count = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (blueVisited[i][j] && redVisited[i][j]) 
            {
                count++;
            }
        }
    }

    return count;
}

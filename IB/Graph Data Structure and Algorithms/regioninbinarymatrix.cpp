const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(vector<vector<int>>& A, int x, int y) 
{
    int N = A.size();
    int M = A[0].size();
    return (x >= 0 && x < N && y >= 0 && y < M && A[x][y] == 1);
}

int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int M = A[0].size();
    int maxRegionSize = 0;

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j) 
        {
            if (A[i][j] == 1 && !visited[i][j]) 
            {
                int regionSize = 0;

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) 
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    regionSize++;

                    for (int dir = 0; dir < 8; ++dir) 
                    {
                        int newX = x + dx[dir];
                        int newY = y + dy[dir];

                        if (isValid(A, newX, newY) && !visited[newX][newY]) 
                        {
                            q.push({newX, newY});
                            visited[newX][newY] = true;
                        }
                    }
                }

                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }

    return maxRegionSize;
}

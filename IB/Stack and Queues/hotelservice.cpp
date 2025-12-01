int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, 1, -1};

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (A[i][j] == 1) 
            {
                q.push({i, j});
                visited[i][j] = true;
                distance[i][j] = 0;
            }
        }
    }

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) 
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) 
            {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    vector<int> result;
    for (const auto& coord : B) 
    {
        int x = coord[0] - 1;
        int y = coord[1] - 1;
        result.push_back(distance[x][y]);
    }

    return result;
}

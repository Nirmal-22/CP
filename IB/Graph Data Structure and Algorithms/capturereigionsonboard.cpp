void Solution::solve(vector<vector<char> > &A) {
   int N = A.size();
    if (N == 0) return;
    int M = A[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) 
    {
        if (A[i][0] == 'O') 
        {
            visited[i][0] = true;
            q.push({i, 0});
        }

        if (A[i][M - 1] == 'O') 
        {
            visited[i][M - 1] = true;
            q.push({i, M - 1});
        }
    }

    for (int j = 0; j < M; j++) 
    {
        if (A[0][j] == 'O') 
        {
            visited[0][j] = true;
            q.push({0, j});
        }
        if (A[N - 1][j] == 'O') 
        {
            visited[N - 1][j] = true;
            q.push({N - 1, j});
        }
    }

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] == 'O' && !visited[nx][ny]) 
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (A[i][j] == 'O' && !visited[i][j]) 
            {
                A[i][j] = 'X';
            }
        }
    }
}

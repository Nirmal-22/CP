struct Cell 
{
    int x, y, dist;
    Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isValidCell(int x, int y, int A, int B) 
{
    return (x >= 1 && x <= A && y >= 1 && y <= B);
}

int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));

    queue<Cell> q;

    q.push(Cell(C, D, 0));

    visited[C][D] = true;

    while (!q.empty()) 
    {
        Cell curr = q.front();
        q.pop();

        if (curr.x == E && curr.y == F) 
        {
            return curr.dist;
        }

        for (int i = 0; i < 8; i++) 
        {
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];

            if (isValidCell(nextX, nextY, A, B) && !visited[nextX][nextY]) 
            {
                visited[nextX][nextY] = true;
                q.push(Cell(nextX, nextY, curr.dist + 1));
            }
        }
    }

    return -1;
}

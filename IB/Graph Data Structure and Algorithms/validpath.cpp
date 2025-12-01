#define MAX 105
#define pii pair<int, int>
#define mp make_pair

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isInside(int x, int y, int X, int Y) 
{
    if (x >= 0 && x <= X && y >= 0 && y <= Y)
        return true;
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
{
    vector<vector<bool>> visited(MAX, vector<bool>(MAX));
    vector<vector<bool>> isCircle(MAX, vector<bool>(MAX));

    for (int i = 0; i < C; i++) 
    {
        for (int x = max(0, E[i] - D); x <= min(A, E[i] + D); x++) 
        {
            for (int y = max(0, F[i] - D); y <= min(B, F[i] + D); y++) 
            {
                if ((x - E[i]) * (x - E[i]) + (y - F[i]) * (y - F[i]) <= D * D)
                    isCircle[x][y] = true;
            }
        }
    }

    if (isCircle[0][0] || isCircle[A][B])
        return "NO";

    queue<pii> q;
    q.push(mp(0, 0));
    visited[0][0] = true;

    while (!q.empty()) 
    {
        pii curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == A && y == B)
            return "YES";

        for (int i = 0; i < 8; i++) 
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isInside(newX, newY, A, B) && !visited[newX][newY] && !isCircle[newX][newY]) 
            {
                visited[newX][newY] = true;
                q.push(mp(newX,newY));
            }
        }
    }

    return "NO";
}

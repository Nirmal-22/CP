int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValidCell(int x, int y, int N, vector<vector<int>>& A) 
{
    return (x >= 0 && x < N && y >= 0 && y < N && A[x][y] !=0);
}

int Solution::checkPath(vector<vector<int> > &A) 
{
    int N = A.size();
    
    int sourceX = -1, sourceY = -1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (A[i][j] == 1) 
            {
                sourceX = i;
                sourceY = j;
                break;
            }
        }
        if (sourceX != -1) 
        {
            break;
        }
    }
    
    if (sourceX == -1) 
    {
        return 0;
    }
    
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    
    A[sourceX][sourceY] = -1;
    
    while (!q.empty()) 
    {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        
        if (A[x][y] == 2) 
        {
            return 1;
        }
        
        for (int dir = 0; dir < 4; dir++) 
        {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            
            if (isValidCell(newX, newY, N, A)) 
            {
                q.push({newX, newY});
                A[newX][newY] = -1;
            }
        }
    }
    
    return 0;
}

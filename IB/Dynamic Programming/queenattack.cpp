vector<vector<int> > Solution::queenAttack(vector<string> &A) 
{
    int N=A.size();
    int M=A[0].size();
    
    vector<vector<int>> result(N, vector<int>(M, 0));
    
    // Define eight possible directions a queen can attack: up, down, left, right, and four diagonals
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] == '1') {
                for (int d = 0; d < 8; ++d) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];
                    while (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                        result[newRow][newCol]++;
                        if (A[newRow][newCol] == '1') {
                            break;
                        }
                        newRow += directions[d][0];
                        newCol += directions[d][1];
                    }
                }
            }
        }
    }
    
    return result;
}

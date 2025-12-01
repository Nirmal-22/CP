void Solution::rotate(vector<vector<int> > &A) 
{
    int N = A.size();

    for (int i = 0; i < N; ++i) 
    {
        for (int j = i; j < N; ++j) 
        {
            std::swap(A[i][j], A[j][i]);
        }
    }

    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N / 2; ++j) 
        {
            std::swap(A[i][j], A[i][N - 1 - j]);
        }
    }

}

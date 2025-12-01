int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            A[i][j] += max(A[i+1][j], A[i+1][j+1]);
        }
    }

    return A[0][0];
}

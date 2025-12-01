int Solution::maxcoin(vector<int> &A) {
   int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; ++len) 
    {
        for (int i = 0; i <= n - len; ++i) 
        {
            // int j = i + len - 1;
            // dp[i][j] = max(A[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
            //               A[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            
            int j = i + len - 1;
            int x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            int y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            int z = (i <= j - 2) ? dp[i][j - 2] : 0;

            dp[i][j] = max(A[i] + min(x, y), A[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int Solution::solve(vector<vector<int> > &A) {
    if (A.empty()) return 0;

    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first row of dp with the costs of painting the first house.
    dp[0] = A[0];

    for (int i = 1; i < n; ++i) 
    {
        // Calculate the minimum cost for painting the current house with each color.
        dp[i][0] = A[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = A[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = A[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // The minimum cost will be the minimum of the last row of dp.
    return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}

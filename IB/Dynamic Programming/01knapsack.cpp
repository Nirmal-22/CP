int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; ++i) 
    {
        for (int w = 1; w <= C; ++w) 
        {
            if (B[i - 1] <= w) 
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - B[i - 1]] + A[i - 1]);
            } 
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][C];
}

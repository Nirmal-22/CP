int Solution::solve(vector<vector<int> > &A) {
    if (A.empty() || A[0].empty()) 
    {
        return 0;
    }
    
    int rows = A.size();
    int cols = A[0].size();
    int maxSide = 0;
    
    // Create a DP A to store the size of the largest square ending at each cell
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (A[i][j] == 1) 
            {
                if (i == 0 || j == 0) 
                {
                    dp[i][j] = 1;
                } 
                else 
                {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    
    // for(int i=0;i<rows;i++)
    // {for(int j=0;j<cols;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return maxSide * maxSide;
}

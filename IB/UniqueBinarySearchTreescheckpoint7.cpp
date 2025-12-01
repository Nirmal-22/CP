int Solution::lis(const vector<int> &A) {
    int n = A.size();
    if (n == 0) 
    {
        return 0;
    }

    std::vector<int> dp(n, 1); 
    
    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (A[i] > A[j]) 
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

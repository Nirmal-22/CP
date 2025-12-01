int Solution::maxProfit(const vector<int> &A) 
{
    if (A.empty())
        return 0;

    int n = A.size();
    std::vector<int> dp(n, 0); 

    int minPrice = A[0]; 

    for (int i = 1; i < n; ++i) 
    {
        int currentProfit = A[i] - minPrice;
        
        dp[i] = std::max(dp[i - 1], currentProfit);

        minPrice = std::min(minPrice, A[i]);
    }

    return dp[n - 1];
}

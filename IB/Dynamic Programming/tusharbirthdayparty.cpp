int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int n = C.size();
    int maxCapacity = *max_element(A.begin(), A.end()); // Maximum eating capacity among friends

    vector<int> dp(maxCapacity + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 cost for 0 capacity

    for (int i = 1; i <= maxCapacity; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (i >= B[j]) 
            {
                dp[i] = min(dp[i], dp[i - B[j]] + C[j]);
            }
        }
    }

    int minCost = 0;
    for (int i = 0; i < A.size(); ++i) 
    {
        minCost += dp[A[i]];
    }

    return minCost;
}

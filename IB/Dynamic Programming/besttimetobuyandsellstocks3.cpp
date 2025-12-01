int Solution::maxProfit(const vector<int> &A) 
{
    int n = A.size();
    if (n <= 1) 
    {
        return 0;
    }
    
    vector<int> profit1(n, 0);  // Maximum profit with at most 1 transaction
    vector<int> profit2(n, 0);  // Maximum profit with at most 2 transactions
    
    int minPrice = A[0];
    for (int i = 1; i < n; ++i) 
    {
        profit1[i] = max(profit1[i - 1], A[i] - minPrice);
        minPrice = min(minPrice, A[i]);
    }
    
    int maxPrice = A[n - 1];
    for (int i = n - 2; i >= 0; --i) 
    {
        profit2[i] = max(profit2[i + 1], maxPrice - A[i]);
        maxPrice = max(maxPrice, A[i]);
    }
    
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) 
    {
        maxProfit = max(maxProfit, profit1[i] + profit2[i]);
    }
    
    return maxProfit;
}

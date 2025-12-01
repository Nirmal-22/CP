int Solution::maxProfit(const vector<int> &A) 
{
    int maxProfit = 0;
    for (int i = 1; i < A.size(); ++i) 
    {
        if (A[i] > A[i - 1]) 
        {
            maxProfit += A[i] - A[i - 1];
        }
    }
    return maxProfit;
}

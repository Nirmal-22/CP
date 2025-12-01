int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();

    std::vector<int> maxFromLeft(n, 0);
    std::vector<int> minFromRight(n, 0);

    int max_val = A[0];
    for (int i = 0; i < n; ++i) 
    {
        maxFromLeft[i] = max_val;
        max_val = std::max(max_val, A[i]);
    }

    int min_val = A[n - 1];
    for (int i = n - 1; i >= 0; --i) 
    {
        minFromRight[i] = min_val;
        min_val = std::min(min_val, A[i]);
    }

    for (int i = 1; i < n - 1; ++i) 
    {
        if (A[i] > maxFromLeft[i] && A[i] < minFromRight[i]) 
        {
            return 1;
        }
    }

    return 0;
}

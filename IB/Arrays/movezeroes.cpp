vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int nonZeroIndex = 0;

    for (int i = 0; i < n; i++) 
    {
        if (A[i] != 0) 
        {
            A[nonZeroIndex] = A[i];
            nonZeroIndex++;
        }
    }

    while (nonZeroIndex < n) 
    {
        A[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
    return A;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int xorSum = 0;
    int count = 0;
    unordered_map<int, int> xorCount;

    for (int i = 0; i < n; ++i) 
    {
        xorSum ^= A[i];

        if (xorSum == B)
            count++;

        if (xorCount.find(xorSum ^ B) != xorCount.end())
            count += xorCount[xorSum ^ B];

        xorCount[xorSum]++;
    }

    return count;
}

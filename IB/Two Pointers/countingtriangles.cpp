const int MOD = 1000000007;

int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    int count = 0;
    
    // Sort the input array
    std::sort(A.begin(), A.end());
    
    for (int i = 0; i < n - 2; ++i) 
    {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; ++j) 
        {
            // Find the rightmost valid k
            while (k < n && A[i] + A[j] > A[k]) 
            {
                ++k;
            }
            
            // Increment count with the number of valid triangles
            count = (count + (k - j - 1)) % MOD;
        }
    }
    
    return count;
}

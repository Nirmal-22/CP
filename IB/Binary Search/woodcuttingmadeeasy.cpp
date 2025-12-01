int Solution::solve(vector<int> &A, int B) {
    
    int N=A.size();
    int max_height = *max_element(A.begin(), A.end());
    int left = 0, right = max_height; 

    while (left < right) 
    {
        int mid = left + (right - left + 1) / 2; 

        long long total_wood = 0; 
        for (int i = 0; i < N; i++) 
        {
            if (A[i] > mid) 
            {
                total_wood += A[i] - mid;
            }
        }

        if (total_wood >= B) 
        {
            left = mid; 
        } 
        else 
        {
            right = mid - 1; 
        }
    }

    return left;
}

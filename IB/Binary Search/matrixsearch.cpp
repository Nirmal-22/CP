int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size();    
    int M = A[0].size(); 
    
    int low = 0;        
    int high = N * M - 1; 
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        
        int row = mid / M; 
        int col = mid % M;
        
        if (A[row][col] == B) 
        {
            return 1; 
        } 
        else if (A[row][col] < B) 
        {
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1; 
        }
    }
    
    return 0; 
}

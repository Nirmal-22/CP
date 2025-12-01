int binarySearch(vector<int>& A, int low, int high, int B, bool isAscending) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == B)
            return mid;
        
        if (isAscending) 
        {
            if (A[mid] < B)
                low = mid + 1;
            else
                high = mid - 1;
        } 
        else 
        {
            if (A[mid] < B)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;  
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int low = 0;
    int high = n - 1;

    int peakIndex;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) 
        {
            peakIndex = mid;
            break;
        } 
        else if (A[mid] > A[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    int result = binarySearch(A, 0, peakIndex, B, true);
    if (result != -1)
        return result;

    result = binarySearch(A, peakIndex + 1, n - 1, B, false);
    return result;
}

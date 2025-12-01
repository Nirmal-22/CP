int Solution::searchInsert(vector<int> &A, int B) {
    int left = 0;
    int right = A.size() - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == B) 
        {
            return mid;
        } 
        else if (A[mid] < B) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    return left;
}

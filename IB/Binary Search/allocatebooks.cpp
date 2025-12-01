bool check(std::vector<int>& A, int B, int maxPages) 
{
    int students = 1;
    int pages = 0;
    for (int i = 0; i < A.size(); i++) 
    {
        if (A[i] > maxPages) 
        {
            return false;
        }

        if (pages + A[i] > maxPages) 
        {
            students++;
            pages = A[i];
            if (students > B) 
            {
                return false;
            }
        } 
        else 
        {
            pages += A[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
        int n = A.size();
    if (n < B) 
    {
        return -1;
    }
    int totalPages = 0;
    int maxPages = 0;
    for (int i = 0; i < n; i++) 
    {
        totalPages += A[i];
        maxPages = std::max(maxPages, A[i]);
    }
    int start = maxPages;
    int end = totalPages;
    int result = -1;
    while (start <= end) 
    {
        int mid = start + (end - start) / 2;
        if (check(A, B, mid)) 
        {
            result = mid;
            end = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }
    }
    return result;
}

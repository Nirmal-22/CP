vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int left = 0, right = 0;  // Window pointers
    int maxZeroes = 0;       // Count of zeroes in the current window
    int maxWindowSize = 0;   // Maximum window size found so far
    int startIdx = 0;        // Start index of the maximum window
    vector<int> result;

    while (right < A.size()) 
    {
        if (A[right] == 0) 
        {
            maxZeroes++;
        }

        while (maxZeroes > B) 
        {
            if (A[left] == 0) 
            {
                maxZeroes--;
            }
            left++;
        }

        int currentWindowSize = right - left + 1;
        if (currentWindowSize > maxWindowSize) 
        {
            maxWindowSize = currentWindowSize;
            startIdx = left;
        }

        right++;
    }

    for (int i = startIdx; i < startIdx + maxWindowSize; i++) 
    {
        result.push_back(i);
    }

    return result;
}

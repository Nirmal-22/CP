int Solution::solve(vector<int> &A, int B) {
        int left = 0;
    int maxLen = 0;
    int zeroCount = 0;

    for (int right = 0; right < A.size(); ++right) 
    {
        if (A[right] == 0) 
        {
            zeroCount++;
        }

        while (zeroCount > B) 
        {
            if (A[left] == 0) 
            {
                zeroCount--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

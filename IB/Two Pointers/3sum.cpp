int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;
    int N = A.size();

    for (int i = 0; i < N - 2; i++) 
    {
        int left = i + 1;
        int right = N - 1;

        while (left < right) 
        {
            int currentSum = A[i] + A[left] + A[right];
            int currentDiff = abs(currentSum - B);
            
            // if(currentDiff==0)
            // return B;
            if (currentDiff < minDiff) 
            {
                minDiff = currentDiff;
                closestSum = currentSum;
            }

            if (currentSum < B) 
                left++;
            else 
                right--;
        }
    }

    return closestSum;
}
int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    int left = 0, right = 0;
    long long currentSum = 0;
    int count = 0;

    while (right < n) 
    {
        currentSum += A[right];

        while (currentSum >= B) 
        {
            currentSum -= A[left];
            left++;
        }

        // Increment count by the number of subarrays ending at index 'right'
        count += (right - left + 1);
        /*  1
            1 2
              2
            1 2 3
              2 3
                3 */
    
        right++;
    }

    return count;
}

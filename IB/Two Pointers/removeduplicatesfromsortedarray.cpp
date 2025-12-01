int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    
    if (n <= 1) 
    {
        return n;
    }
    
    int uniqueIndex = 0;
    
    for (int i = 1; i < n; ++i) 
    {
        if (A[i] != A[uniqueIndex]) 
        {
            uniqueIndex++;
            A[uniqueIndex] = A[i];
        }
    }
    
    return uniqueIndex + 1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

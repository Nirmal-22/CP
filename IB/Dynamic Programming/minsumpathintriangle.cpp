int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for (int row = A.size() - 2; row >= 0; --row) 
    {
        for (int col = 0; col < A[row].size(); ++col) 
        {
            A[row][col] += std::min(A[row + 1][col], A[row + 1][col + 1]);
        }
    }
    return A[0][0];
}

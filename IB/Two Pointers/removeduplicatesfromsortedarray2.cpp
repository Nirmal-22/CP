int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if (n <= 2) 
    {
        return n; // No need to remove duplicates if there are at most 2 elements.
    }

    int uniqueIdx = 2; // Index to place the next unique element.

    for (int i = 2; i < n; ++i) 
    {
        if (A[uniqueIdx - 2] != A[i]) 
        {
            A[uniqueIdx] = A[i];
            ++uniqueIdx;
        }
    }

    // Resize the vector to the new length and return it.
    A.resize(uniqueIdx);
    return uniqueIdx;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

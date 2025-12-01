vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) 
    {
        int leftSquare = A[left] * A[left];
        int rightSquare = A[right] * A[right];

        if (leftSquare >= rightSquare) 
        {
            result[index] = leftSquare;
            left++;
        } 
        else 
        {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
}

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> matrix(A, vector<int>(A, 0));
    int top = 0, bottom = A - 1, left = 0, right = A - 1;
    int num = 1;

    while (num <= A * A) 
    {
        for (int i = left; i <= right; i++) 
        {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) 
        {
            matrix[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) 
        {
            matrix[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) 
        {
            matrix[i][left] = num++;
        }
        left++;
    }

    return matrix;
}
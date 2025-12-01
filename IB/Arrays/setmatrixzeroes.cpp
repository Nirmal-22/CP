void Solution::setZeroes(vector<vector<int> > &A) {
    int rows = A.size();
    if (rows == 0) return;
    int cols = A[0].size();

    bool zeroFirstRow = false;
    bool zeroFirstCol = false;

    for (int i = 0; i < cols; i++) 
    {
        if (A[0][i] == 0) 
        {
            zeroFirstRow = true;
            break;
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        if (A[i][0] == 0) {
            zeroFirstCol = true;
            break;
        }
    }

    for (int i = 1; i < rows; i++) 
    {
        for (int j = 1; j < cols; j++) 
        {
            if (A[i][j] == 0) 
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++) 
    {
        if (A[i][0] == 0) 
        {
            for (int j = 1; j < cols; j++) 
            {
                A[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < cols; j++) 
    {
        if (A[0][j] == 0) 
        {
            for (int i = 1; i < rows; i++) 
            {
                A[i][j] = 0;
            }
        }
    }

    if (zeroFirstRow) 
    {
        for (int i = 0; i < cols; i++) 
        {
            A[0][i] = 0;
        }
    }

    if (zeroFirstCol) 
    {
        for (int i = 0; i < rows; i++) 
        {
            A[i][0] = 0;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

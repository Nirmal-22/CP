int countElements(const vector<vector<int>>& A, int target) {
    int count = 0;
    int rows = A.size();
    int cols = A[0].size();
    int row = 0;
    int col = cols - 1;

    while (row < rows) {
        if (A[row][col] <= target) {
            count += col + 1;
            
            row++;
            col=cols-1;
        } else {
            col--;
            
            if(col<0) {row++; col=cols-1;}
        }
    }

    return count;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();

    int start = 0;
    int end = INT_MAX;

    while (start < end) {
        int mid = start + (end - start) / 2;
        int count = countElements(A, mid);

        if (count <= (rows * cols) / 2) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

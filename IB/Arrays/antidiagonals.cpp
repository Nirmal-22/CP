vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> result;
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        int r = 0;
        int c = i;
        vector<int> diagonal;
        while (r < n && c >= 0) {
            diagonal.push_back(A[r][c]);
            r++;
            c--;
        }
        result.push_back(diagonal);
    }

    for (int i = 1; i < n; i++) {
        int r = i;
        int c = n - 1;
        vector<int> diagonal;
        while (r < n && c >= 0) {
            diagonal.push_back(A[r][c]);
            r++;
            c--;
        }
        result.push_back(diagonal);
    }

    return result;
}

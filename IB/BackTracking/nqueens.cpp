vector<vector<string> > Solution::solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> v(n, string(n, '.'));
    vector<int> col(n, 1), diag1(2*n-1, 1), diag2(2*n-1, 1);

    function<void(int)> dfs = [&](int i)
    {
        if(i == n)
        {
            ans.push_back(v);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(col[j] && diag1[i+j] && diag2[i-j+n-1])
            {
                col[j] = diag1[i+j] = diag2[i-j+n-1] = 0;
                v[i][j] = 'Q';
                dfs(i+1);
                v[i][j] = '.';
                col[j] = diag1[i+j] = diag2[i-j+n-1] = 1;
            }
        }
    };
    dfs(0);
    return ans;
}

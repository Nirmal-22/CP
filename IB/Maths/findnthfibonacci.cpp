vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    int n = a.size();
    vector<vector<long long>> ans(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return ans;
}

vector<vector<long long>> matrixExponentiate(const vector<vector<long long>>& a, int n) {
    if (n == 0) {
        int sz = a.size();
        vector<vector<long long>> ans(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            ans[i][i] = 1;
        }
        return ans;
    }

    if (n == 1)
        return a;

    vector<vector<long long>> temp = matrixExponentiate(a, n / 2);
    vector<vector<long long>> ans = multiply(temp, temp);

    if (n % 2 == 1) {
        ans = multiply(ans, a);
    }

    return ans;
}

int Solution::solve(int A) {
    vector<vector<long long>> a = {{1, 1}, {1, 0}};
    vector<vector<long long>> ans = matrixExponentiate(a, A - 1);

    return ans[0][0];
}
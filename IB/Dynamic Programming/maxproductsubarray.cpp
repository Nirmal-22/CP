int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    if (n == 0) 
    {
        return 0;
    }

    int maxProd = A[0];
    int minProd = A[0];
    int result = maxProd;

    for (int i = 1; i < n; i++) {
        if (A[i] < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max(A[i], maxProd * A[i]);
        minProd = min(A[i], minProd * A[i]);

        result = max(result, maxProd);
    }

    return result;
}

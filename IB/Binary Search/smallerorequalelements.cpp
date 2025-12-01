int Solution::solve(vector<int> &A, int B) {
    int left = 0;
    int right = A.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (A[mid] <= B) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result + 1;
}

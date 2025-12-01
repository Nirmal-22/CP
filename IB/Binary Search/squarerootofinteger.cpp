int Solution::sqrt(int A) {
        if (A == 0 || A == 1) {
        return A;
    }

    int start = 1;
    int end = A;
    int result;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (mid * mid == A) {
            return mid;
        }

        if (mid <= A / mid) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    return result;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    int oddCount = 0;
    unordered_map<int, int> oddCountFrequency;

    for (int i = 0; i < n; ++i) {
        if (A[i] % 2 == 1) {
            oddCount++;
        }

        if (oddCount == B) {
            count++;
        }

        if (oddCountFrequency.find(oddCount - B) != oddCountFrequency.end()) {
            count += oddCountFrequency[oddCount - B];
        }

        oddCountFrequency[oddCount]++;
    }

    return count;
}

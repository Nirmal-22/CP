int Solution::isScramble(const string A, const string B) {
    if (A == B) return 1;
    if (A.size() != B.size()) return 0;
    int n = A.size();
    unordered_map<char, int> count;
    
    for (int i = 0; i < n; i++) 
    {
        count[A[i]]++;
        count[B[i]]--;
    }
    for (auto it: count) 
    {
        if (it.second != 0) return 0;
    }
    for (int i = 1; i < n; i++) 
    {
        if (isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i), B.substr(i))) return 1;
        if (isScramble(A.substr(0, i), B.substr(n - i)) && isScramble(A.substr(i), B.substr(0, n - i))) return 1;
    }
    return 0;
}

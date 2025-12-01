int Solution::singleNumber(const vector<int> &A) {
    int result = 0;
    for (int num : A)
    {
        result ^= num;
    }
    return result;
}

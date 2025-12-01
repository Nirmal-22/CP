vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    std::vector<int> result;
    int n = std::max(A.size(), B.size());
    int carry = 0;

    std::vector<int> reversedA(A.rbegin(), A.rend());
    std::vector<int> reversedB(B.rbegin(), B.rend());

    while (reversedA.size() < n) 
    {
        reversedA.push_back(0);
    }

    while (reversedB.size() < n) 
    {
        reversedB.push_back(0);
    }

    for (int i = 0; i < n; ++i) 
    {
        int sum = reversedA[i] + reversedB[i] + carry;
        carry = sum / 10;
        result.push_back(sum % 10);
    }

    while (carry) 
    {
        result.push_back(carry % 10);
        carry /= 10;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

vector<int> countPowerOf2Divisors(int maxLimit) {
    vector<int> count(maxLimit + 1, 0);
    vector<int> divisorCount(maxLimit + 1, 0);

    for (int i = 1; i <= maxLimit; i++) {
        for (int j = i; j <= maxLimit; j += i) {
            divisorCount[j]++;
        }
    }

    for (int i = 1; i <= maxLimit; i++) {
        if ((divisorCount[i] & (divisorCount[i] - 1)) == 0) {
            count[i] = 1;
        }
    }

    for (int i = 1; i <= maxLimit; i++) {
        count[i] += count[i - 1];
    }

    return count;
}

vector<int> Solution::powerfulDivisors(vector<int> &A) 
{
    int maxLimit = *max_element(A.begin(), A.end());
    vector<int> result;
    vector<int> count = countPowerOf2Divisors(maxLimit);

    for (int x : A) {
        result.push_back(count[x]);
    }

    return result;
}

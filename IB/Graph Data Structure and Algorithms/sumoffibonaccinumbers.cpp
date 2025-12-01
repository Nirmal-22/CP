int Solution::fibsum(int A) {
    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (fib.back() <= A) {
        int nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(nextFib);
    }

    std::sort(fib.rbegin(), fib.rend());

    int count = 0;

    for (int i = 0; i < fib.size(); i++) {
        while (A >= fib[i]) {
            A -= fib[i];
            count++;
        }
    }

    return count;
}

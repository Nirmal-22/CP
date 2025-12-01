int Solution::solve(vector<int> &A, int B) {
        int n = A.size();
    int profit = 0;

    // priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>> maxHeap;

    for (int i = 0; i < n; i++) 
    {
        maxHeap.push(A[i]);
    }

    while (B > 0 && !maxHeap.empty()) 
    {
        int minA = maxHeap.top();
        maxHeap.pop();

        profit += minA;

        minA--;

        if (minA > 0) 
        {
            maxHeap.push(minA);
        }

        B--;
    }

    return profit;
}

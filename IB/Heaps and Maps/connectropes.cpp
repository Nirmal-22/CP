int Solution::solve(vector<int> &A) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < A.size(); i++) 
    {
        minHeap.push(A[i]);
    }

    int cost = 0;

    while (minHeap.size() > 1) 
    {
        int min1 = minHeap.top();
        minHeap.pop();

        int min2 = minHeap.top();
        minHeap.pop();

        int newRope = min1 + min2;
        cost += newRope;

        minHeap.push(newRope);
    }

    return cost;
}

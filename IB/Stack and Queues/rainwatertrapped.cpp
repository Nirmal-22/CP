int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int trappedWater = 0;
    std::stack<int> stack;

    for (int i = 0; i < n; i++) 
    {
        while (!stack.empty() && A[i] > A[stack.top()]) 
        {
            int top = stack.top();
            stack.pop();

            if (!stack.empty()) {
                int distance = i - stack.top() - 1;
                int boundedHeight = std::min(A[i], A[stack.top()]) - A[top];
                trappedWater += distance * boundedHeight;
            }
        }

        stack.push(i);
    }

    return trappedWater;
}


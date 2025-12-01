int Solution::largestRectangleArea(vector<int> &A) 
{
    int n = A.size();
    stack<int> stk;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) 
    {
        while (!stk.empty() && (i == n || A[stk.top()] >= A[i])) 
        {
            int height = A[stk.top()];
            stk.pop();

            int width = stk.empty() ? i : (i - stk.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        stk.push(i);
    }

    return maxArea;
}

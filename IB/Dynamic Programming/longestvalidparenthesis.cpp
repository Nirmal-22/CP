int Solution::longestValidParentheses(string A) {
    int n = A.length();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    int maxLength = 0;

    for (int i = 1; i < n; i++) 
    {
        if (A[i] == ')') 
        {
            if (A[i - 1] == '(') 
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } 
            else if (i - dp[i - 1] > 0 && A[i - dp[i - 1] - 1] == '(') 
            {
                dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxLength = max(maxLength, dp[i]);
        }
    }
    return maxLength;
}

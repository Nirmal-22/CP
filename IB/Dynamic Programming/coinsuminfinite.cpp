int Solution::coinchange2(vector<int> &A, int B) {
    vector<int> dp(B + 1, 0);
    dp[0] = 1;

    for (int coin : A) 
    {
        for (int i = coin; i <= B; i++) 
        {
            dp[i] = (dp[i] + dp[i - coin]) % 1000007;
        }
    }

    return dp[B];
}

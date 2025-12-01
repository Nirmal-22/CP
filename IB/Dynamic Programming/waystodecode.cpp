const int MOD = 1000000007;

int Solution::numDecodings(string A) 
{
    int n = A.size();
    vector<long long> dp(n + 1, 0);
    
    dp[0] = 1; // Base case: there's one way to decode an empty string
    
    for (int i = 1; i <= n; i++) 
    {
        if (A[i - 1] != '0') 
        {
            dp[i] = dp[i - 1]; // If the current digit is not zero, we can form a valid decoding with it alone
        }
        
        if (i > 1 && (A[i - 2] == '1' || (A[i - 2] == '2' && A[i - 1] <= '6'))) 
        {
            dp[i] = (dp[i] + dp[i - 2]) % MOD; // Check if the previous and current digit can form a valid decoding
        }
    }
    
    return dp[n];
}

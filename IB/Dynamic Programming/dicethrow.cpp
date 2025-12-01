//not my code
int Solution::findDiceSum(int A, int B, int C) 
{
    if(C<=A||B==1) return C==A;
    long long m = 1e9+7;

    vector<vector<long long>> dp(A+1, vector<long long> (C+1)); // dp[i][j] means in i chances, no. of ways to get sum<=j;
    dp[0][0]=1; // initially all dp[i][j]=0 except dp[0][0];

    for(int i=1; i<A+1; i++)
    {
        for(int j=i; j<C+1; j++)
        {
            dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%m; // no. of ways to get sum<=j in i chances = no. of ways to get sum<=j-1 in i chances + no. of ways to get sum = j in i chances
            // no. of ways to get sum = j in i chances = sum(throwing last dice as i from 1 to B => no. of ways to get remaining sum=j-i in remaining i-1 chances)
            if(j-1>=B) 
            dp[i][j] = (m+dp[i][j]-dp[i-1][j-B-1])%m; // which is (no. of ways to get sum<=j-1) - (no. of ways to get sum<=j-B-1) = sum(no. of ways to get sum=j-i for i 1 to B)
        }
    }
    return dp[A][C]%m;
}
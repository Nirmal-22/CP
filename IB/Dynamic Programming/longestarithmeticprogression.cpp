//not my code... mine coming tle

int Solution::solve(const vector<int> &A) 
{
int n = A.size();
    unordered_map<int, int> mp;

    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = A[j] - A[i];
            int need = 2 * A[i] - A[j];

            if (mp.find(need) != mp.end())
            {
                int pos = mp[need];
                dp[i][j] = max(dp[i][j], dp[pos][i] + 1);
            }
            else
                dp[i][j] = 2;

            ans = max(ans, dp[i][j]);
        }

        mp[A[i]] = i;
    }

    return ans;

}

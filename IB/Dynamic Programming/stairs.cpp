int Solution::climbStairs(int A) 
{
    std::vector<int> memo(A + 1, -1); 
    memo[0] = 1;
    memo[1] = 1;

    std::function<int(int)> memoizedClimb = [&](int n)
    {
        if (memo[n] != -1) 
        {
            return memo[n]; 
        }

        memo[n] = memoizedClimb(n - 1) + memoizedClimb(n - 2);
        return memo[n];
    };

    return memoizedClimb(A);
}

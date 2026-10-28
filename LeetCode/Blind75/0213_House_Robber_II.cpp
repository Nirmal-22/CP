// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:

    int solve(vector<int>& nums) {
        int n= nums.size();

        if(n==0) return 0;
        vector<int> dp(n+1, 0);
        dp[0]=0;
        dp[1]= nums[0];

        for(int i=2; i<=n ;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> sub1(nums.begin(), nums.end()-1);
        vector<int> sub2(nums.begin()+1, nums.end());

        return max(solve(sub1), solve(sub2));
    }
};

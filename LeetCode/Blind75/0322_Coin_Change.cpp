// 322. Coin Change
// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& c, int s) {
        vector<int> dp(s+1, s+1);
        dp[0] = 0;
        for(int i=1;i<=s; i++)
        {
            for(int coin: c){
                if(i >= coin){
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[s] > s ? -1:dp[s];
    }
};

// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        return 0;

    int n = prices.size();
    std::vector<int> dp(n, 0); 

    int minPrice = prices[0]; 

    for (int i = 1; i < n; ++i) 
    {
        int currentProfit = prices[i] - minPrice;
        
        dp[i] = std::max(dp[i - 1], currentProfit);

        minPrice = std::min(minPrice, prices[i]);
    }

    return dp[n - 1];
    }
};

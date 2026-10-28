// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        
        sort(can.begin(), can.end());  //imp

        vector<vector<vector<int>>> dp(tar+1);

        dp[0] = {{}};

        for(int c:can){
            for(int sum=c; sum<=tar; sum++){
                for(auto comb: dp[sum-c]){

                    if(comb.empty() || c>=comb.back()){
                        comb.push_back(c);
                        dp[sum].push_back(comb);
                    }
                }
            }
        }

        return dp[tar];
    }
};

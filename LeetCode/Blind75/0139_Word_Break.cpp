// 139. Word Break
// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        unordered_set<string> dict(wd.begin(),wd.end());
        int n= s.size();
        vector<char> dp(n+1, 0);
        dp[0] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0 && !dp[i]; j--){
                if(dp[j] && dict.count(s.substr(j, i-j))) dp[i]=1;
            }
        }

        return dp[n];
    }
};

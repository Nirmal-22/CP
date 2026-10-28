// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        if(n==0 || s[0]=='0') return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            
            int twoD = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(twoD>=10 && twoD<=26)
                dp[i]+=dp[i-2];
        }

        return dp[n];
        
    }
};

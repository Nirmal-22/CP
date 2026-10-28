// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxf=0, left=0, res=0;

        for(int right=0; right<s.size(); right++){
            maxf = max(maxf, ++count[s[right]-'A']);

            while((right-left+1)-maxf > k)
                --count[s[left++]-'A'];
            
            res = max(res, right-left+1);
        }

        return res;
    }
};

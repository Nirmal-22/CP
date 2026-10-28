// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int start=0, maxlen=0;
        for(int i=0;i<s.size();i++){
            start = max(start, last[s[i]]+1);
            maxlen = max(maxlen, i-start+1);
            last[s[i]] = i;
        }
        return maxlen;
    }
};

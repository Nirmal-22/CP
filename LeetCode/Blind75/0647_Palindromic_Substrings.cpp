// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        //2n-1 centers (n single chars + n-1 gaps)
        for (int center = 0; center < 2*n - 1; ++center) {
            int l = center / 2;
            int r = l + center % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++ans;
                --l; ++r;
            }
        }
        return ans;
    }
};

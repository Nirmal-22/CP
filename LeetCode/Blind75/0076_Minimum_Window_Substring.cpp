// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.empty()) return "";

        vector<int> f(128,0);
        for(auto c:t) f[c]++;

        int req=t.size(), l=0, min=INT_MAX, start=0;

        for(int r=0;r<(int)s.size(); r++)
        {
            if(f[s[r]]-- > 0) --req;

            while(req == 0)
            {
                if(r-l+1 < min)
                {
                    min = r-l+1;
                    start = l;
                }
                if(++f[s[l]] > 0) ++req;
                l++;
            }
        }
        return min == INT_MAX ? "" : s.substr(start, min);
    }
};

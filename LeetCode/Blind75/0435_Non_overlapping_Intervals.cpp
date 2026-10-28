// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& it) {
        if(it.empty()) return 0;
        sort(it.begin(), it.end(), [](auto &a, auto &b){ return a[1] < b[1]; });

        int removed = 0;
        int lastEnd = it[0][1];
        for(int i=1; i<it.size(); i++){
            if(it[i][0] < lastEnd) removed++;
            else lastEnd = it[i][1];
        }

        return removed;
    }
};

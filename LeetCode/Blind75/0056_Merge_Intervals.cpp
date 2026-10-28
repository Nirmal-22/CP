// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        if(it.empty()) return {};
        sort(it.begin(), it.end());
        
        vector<vector<int>> merged;
        merged.push_back(it[0]);

        for(int i=1;i<it.size();i++){
            auto &last = merged.back();
            if(it[i][0] <= last[1])
                last[1] = max(last[1], it[i][1]);
            else
                merged.push_back(it[i]);
        }

        return merged;
    }
};

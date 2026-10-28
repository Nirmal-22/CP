// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0, n= intervals.size();

        while(i<n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i++]);
        }   

        int start = newInterval[0], end= newInterval[1];

        while(i<n && intervals[i][0] <= end){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        result.push_back({start, end});

        while(i<n){
            result.push_back(intervals[i++]);
        }

        return result;
    }
};

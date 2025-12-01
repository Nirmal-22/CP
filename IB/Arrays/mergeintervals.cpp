/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> result;
    int n = intervals.size();
    int i = 0;

    while (i < n && intervals[i].end < newInterval.start) 
    {
        result.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i].start <= newInterval.end) 
    {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }

    result.push_back(newInterval);

    while (i < n) 
    {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

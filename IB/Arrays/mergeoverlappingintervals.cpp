/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.empty()) return {};

    std::sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) 
    {
        return a.start < b.start;
    });

    std::vector<Interval> merged;
    merged.push_back(A[0]);

    for (const auto& interval : A) 
    {
        if (interval.start <= merged.back().end) 
        {
            merged.back().end = std::max(merged.back().end, interval.end);
        } 
        else 
        {
            merged.push_back(interval);
        }
    }

    return merged;
}

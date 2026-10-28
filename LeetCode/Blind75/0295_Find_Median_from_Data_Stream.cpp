// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<>> hi;

public:
    MedianFinder() = default;
    
    void addNum(int num) {
        // (lo.empty() || num <= lo.top() ? lo:hi).push(num);
        if(lo.empty() || num<=lo.top()) lo.push(num);
        else hi.push(num);
        
        if(lo.size() > hi.size()+1) { hi.push(lo.top()); lo.pop();}
        else if (hi.size() > lo.size()) {lo.push(hi.top()); hi.pop();}
    }
    
    double findMedian() {
        return lo.size() == hi.size()? (lo.top()+hi.top())/2.0 : lo.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

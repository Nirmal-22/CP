// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<pair<int,int>> elems(freq.begin(), freq.end());
        sort(elems.begin(), elems.end(),
            [](auto &a, auto &b){ return a.second > b.second; });
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(elems[i].first);
        return res;
    }
};

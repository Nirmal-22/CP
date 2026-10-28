// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for(auto& s: strs){
            string key = s;
            sort(key.begin(), key.end());
            buckets[key].push_back(move(s));
        }

        vector<vector<string>> result;
        result.reserve(buckets.size());
        for(auto& [_, grp]: buckets) 
            result.push_back(move(grp));
        return result;
    }
};

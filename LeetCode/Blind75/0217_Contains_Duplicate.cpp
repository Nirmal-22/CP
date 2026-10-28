// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(auto x:nums)
        {
            if(mp[x]==1) return true;
            else
                mp[x]=1;
        }     

        return false;   
    }
};

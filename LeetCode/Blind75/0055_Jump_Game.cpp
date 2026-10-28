// 55. Jump Game
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest=0, n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>furthest) return false;
            furthest = max(furthest, i+nums[i]);
            if(furthest >= n-1) return true;
        }
        return true;
    }
};

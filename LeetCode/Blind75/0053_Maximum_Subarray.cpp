// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
    
        int s=0;
        int max=nums[0];
        for(int i=0;i<n;i++)
        {
            if(s<0 && nums[i]>s)
            s=0;
            
            s+=nums[i];
            
            if(s>max)
            max=s;
            
        }
        
        return max;
    }
};

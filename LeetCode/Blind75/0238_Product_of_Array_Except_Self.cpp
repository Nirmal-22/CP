// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prod=1;
        // vector<int> v0;
        int c=0;
        vector<int> ans(nums.size(),0);
        for(auto x:nums)
        {
            if(x!=0)
            prod*=x;
            else 
            {
                // v0.push_back(x);
                // if(v0.size()>1) return ans;
                c++;
                if(c>1) return ans;
            }
            
        }
        
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            // ans[i]=(0!=nums[i] && c==1)? (prod/nums[i]) :prod;
            if(c==1)
            {
                if(nums[i]!=0) ans[i]=0;
                else ans[i]=prod;
            }
            else
            {
                ans[i]=prod/nums[i];
            }
        }

        return ans;
    }
};

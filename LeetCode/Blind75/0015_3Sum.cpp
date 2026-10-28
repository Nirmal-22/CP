// 15. 3Sum
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int B=0;
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        // int minDiff = INT_MAX;
        int N = nums.size();

        // vector<vector<int>> ans;
        set<vector<int>> ans;
        for (int i = 0; i < N - 2; i++) 
        {
            int left = i + 1;
            int right = N - 1;

            while (left < right) 
            {
                int currentSum = nums[i] + nums[left] + nums[right];
                // int currentDiff = abs(currentSum - B);
                
                // if(currentDiff==0) 
                if(currentSum==0) 
                {
                    ans.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    // break;    
                }
                // return B;
                // if (currentDiff <= minDiff) 
                // {
                //     minDiff = currentDiff;
                //     closestSum = currentSum;
                // }

                else if (currentSum < 0) 
                    left++;
                else 
                    right--;
            }
        }

        // return closestSum;
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;     
    }
};

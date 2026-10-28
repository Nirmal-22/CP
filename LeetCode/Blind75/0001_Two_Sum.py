# 1. Two Sum
# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        dict = {}
        # ans = []

        for i,j in enumerate(nums):

            if target-j in dict:
                # ans = [dict[target-j] , i]
                return [dict[target-j] , i]
                # break

            dict[j] = i
        
        # return ans

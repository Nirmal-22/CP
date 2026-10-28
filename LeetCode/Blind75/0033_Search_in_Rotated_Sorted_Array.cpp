// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

    class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left =0, right = nums.size()-1;

        while(left<=right){
            int mid= left+ (right-left)/2;

            if(nums[mid] == target)
                return mid;

            // if(nums[left] <= nums[mid]){
            //     if(nums[left]<=target && target<nums[mid])
            //         right = mid-1;
            //     else
            //         left = mid+1;
            // }
            // else{
            //     if(nums[mid] < target && target<= nums[right])
            //         left = mid+1;
            //     else
            //         right = mid-1;
            // }

            //there are two sorted parts, if the left one is longer 
            //which includes left and mid and if the target is present between them and the vice versa
            // if statement otherwise else. The above logic also does the same.
            if((nums[left]<=nums[mid]) && (nums[left]<=target && target<nums[mid])
                || (nums[left]>nums[mid] && !(nums[mid]<target && target<=nums[right])))
                right = mid-1;
            else
                left = mid+1;
        }

        return -1;
    }
};

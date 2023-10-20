/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    int leftmost(vector<int>& nums,int target){
        int n=nums.size();
        int l=0,r=n-1;
        int leftmost;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                leftmost=mid;
            }
        }
    }





    vector<int> searchRange(vector<int>& nums, int target) {
        int leftmost=leftmost(nums,target);
        int rightmost=rightmost(nums,target);
        return {leftmost,rightmost};
    }
};
// @lc code=end


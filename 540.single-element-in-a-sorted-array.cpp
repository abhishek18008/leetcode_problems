/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans^=nums[i];
        // }
        // return ans;

        //binary search
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
             (mid % 2 == 1 && nums[mid] == nums[mid - 1]) ){
                l=mid+1;
             }
            else{
                r=mid;
             }
        }
        return nums[l];

    }
};
// @lc code=end


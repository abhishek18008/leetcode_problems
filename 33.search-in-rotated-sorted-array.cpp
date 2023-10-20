/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findpivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }


    int search(vector<int>& nums, int target) {
        int pivot=findpivot(nums);
        int n=nums.size();
        // do a binary search in 0 to pivot-1 and pivot to n-1
        int l=0,r=pivot-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }


        // again do a binary serach
        l=pivot,r=n-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return -1;

       
    }
};
// @lc code=end


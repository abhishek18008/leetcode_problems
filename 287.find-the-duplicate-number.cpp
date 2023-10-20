/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1;
        int r=nums.size()-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            int count=0;
            for(int i=0 ; i<nums.size() ; i++){
                if(nums[i]<=mid)
                count++;
            }
            if(count<=mid){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }
        return l;
    }
};
// @lc code=end


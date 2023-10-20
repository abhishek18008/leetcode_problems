/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        // flip 0 to 1
        int count0=0;
        int i=0,j=0;
        int maxans=0;
        while(j<n){
            if(nums[j]==0){
                count0++;
            }

            if(count0>k){
                while(nums[i]!=0){
                    i++;
                }
                i++;
                count0--;
            }
            maxans=max(maxans,j-i+1);
            j++;

        }
        return maxans;

        
    }
};
// @lc code=end


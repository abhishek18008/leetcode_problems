/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int  n=nums.size();
        int i=0,j=0;
        int sum=0;
        int  minilen=INT_MAX;
        while(j<n){
            sum+=nums[j];
            
                while(sum>=target){
                    sum-=nums[i];
                    minilen=min(minilen,j-i+1);
                    i++;
                }
                
            
            j++;
            
        }
        return minilen==INT_MAX ? 0 :minilen;
        
    }
};
// @lc code=end


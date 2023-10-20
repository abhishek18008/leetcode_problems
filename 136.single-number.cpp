/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int idt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            idt^=nums[i];
        }
        return idt;
        
        
        
    }
};
// @lc code=end


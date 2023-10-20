/*
 * @lc app=leetcode id=2317 lang=cpp
 *
 * [2317] Maximum XOR After Operations 
 */

// @lc code=start
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans= ans |it;
        }
        return ans;
    }
};
// @lc code=end


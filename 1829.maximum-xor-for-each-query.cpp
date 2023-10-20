/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans(n);
        int x=0;
        for(int i=0;i<n;i++){
            x=x^nums[i];
            ans[n-i-1]=(x^((1<<maximumBit)-1));
        }
        return ans;
    }
};
// @lc code=end


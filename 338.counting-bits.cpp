/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        solve(n,ans);
        return ans;
        
        
    }
};
// @lc code=end


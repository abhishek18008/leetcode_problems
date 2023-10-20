/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
 int solve(vector<int>& nums, int idx, int target) {
    // Base case
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (idx == nums.size()) return 0; // Corrected the equality check here

    int take = solve(nums, idx, target - nums[idx]);
    int skip = solve(nums, idx + 1, target);
    return take + skip;
}

int combinationSum4(vector<int>& nums, int target) {
    return solve(nums, 0, target);
}


};
// @lc code=end


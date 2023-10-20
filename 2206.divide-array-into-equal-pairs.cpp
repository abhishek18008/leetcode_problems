/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
class Solution {
public:
    bool divideArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i += 2) {
        if (nums[i] != nums[i + 1]) {
            return false;
        }
    }
    return true;
}

};
// @lc code=end


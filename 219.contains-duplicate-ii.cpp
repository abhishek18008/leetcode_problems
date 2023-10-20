/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
 bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    while (j < n && i<n) {
        if (j - i <= k && i != j) {
            if (nums[i] == nums[j]) {
                return true;
            }
            j++;
        } else {
            i++;
        }
    }
    return false;
}






};
// @lc code=end


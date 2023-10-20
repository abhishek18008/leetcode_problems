/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        const int n = nums.size();
        int rst = 0;
        int acc = 0;
        m[0] = 1;
        for (int i = 0; i < n; ++i) {
            acc += (nums[i]%2);
            rst += m[acc-k];
            m[acc]++;
        }
        return rst;
    }
};
// @lc code=end


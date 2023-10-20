/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
class Solution {
public:
    int N;
    vector<int> dp;
    bool solve(vector<int>& nums, int idx) {
        if (idx >= N) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool ans = false;
        
        // If the first two elements are same
        if (idx <= N - 2 && nums[idx] == nums[idx + 1]) {
            ans = solve(nums, idx + 2);
        }
        if (ans) return dp[idx]=  true;
        
        // If first 3 elements are same or have consecutive increasing elements
        if (idx <= N - 3 && ((nums[idx] == nums[idx + 1] && nums[idx + 1] == nums[idx + 2]) ||
            (nums[idx + 2] - nums[idx + 1] == 1 && nums[idx + 1] - nums[idx] == 1))) {
            ans = solve(nums, idx + 3);
        }
        return dp[idx]=ans;
    }

    bool validPartition(vector<int>& nums) {
        N = nums.size();
        dp.resize(N,-1);
        return solve(nums, 0);
    }
};

// @lc code=end


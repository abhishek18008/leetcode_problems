/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution {
public:

int eggDrop2EggsNFloors(int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));

    // Base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0; // With 0 eggs, no floors can be determined
    }
    for (int j = 0; j <= 1; ++j) {
        dp[0][j] = 0; // With 0 floors, no drops are needed
        dp[1][j] = 1; // With 1 floor, only one drop is needed
    }

    // Fill the dp table
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            dp[i][j] = std::numeric_limits<int>::max();
            for (int k = 1; k <= i; ++k) {
                // Compute the number of drops for the worst-case scenario
                int worst_case_drops = 1 + std::max(dp[k - 1][j - 1], dp[i - k][j]);
                dp[i][j] = std::min(dp[i][j], worst_case_drops);
            }
        }
    }

    return dp[n][2];
}



};
// @lc code=end


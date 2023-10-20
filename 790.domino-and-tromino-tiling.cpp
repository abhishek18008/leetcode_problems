/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
    int N;
    const int MOD = 1e9 + 7; // Define the modulo constant

    // 0 --- no gap
    // 1 --- top gap
    // -1 --- bottom gap
    // All in the previous column
    int solve(int i, int gap, vector<vector<int>>& dp) {
        if (i == N && gap == 0) return 1;
        else if (i > N ) return 0; // Change this to return 0

        // Check if the result is already computed
        if (dp[i][gap+1] != -1) return dp[i][gap+1];

        long long ways = 0; // Use long long to avoid overflow

        // All previous rows are full
        if (gap == 0) {
            ways += solve(i + 1, 0, dp);
            ways += solve(i + 2, -1, dp);
            ways += solve(i + 2, 1, dp);
            ways += solve(i + 2, 0, dp);
        }
        else if (gap == 1) {
            ways += solve(i + 1, -1, dp);
            ways += solve(i + 1, 0, dp);
        }
        else {
            ways += solve(i + 1, 1, dp);
            ways += solve(i + 1, 0, dp);
        }

        // Store the result and return it modulo MOD
        dp[i][gap+1] = ways % MOD;
        return dp[i][gap+1];
    }

    int numTilings(int n) {
        N = n;
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
        return solve(0, 0, dp);
    }
};

// @lc code=end


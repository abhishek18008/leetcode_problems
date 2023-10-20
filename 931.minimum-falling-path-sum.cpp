/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Create a DP table to store minimum falling path sums
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Copy the last row of the matrix to the DP table
    for (int i = 0; i < n; ++i) {
        dp[n - 1][i] = matrix[n - 1][i];
    }
    
    // Start from the second last row and move upwards
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            // Calculate the minimum falling path sum for the current cell
            int down = dp[i + 1][j];
            int right = (j + 1 < n) ? dp[i + 1][j + 1] : INT_MAX;
            int left = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
            
            dp[i][j] = matrix[i][j] + min(down, min(right, left));
        }
    }
    
    // Find the minimum falling path sum in the first row
    int mini = INT_MAX;
    for (int i = 0; i < n; ++i) {
        mini = min(mini, dp[0][i]);
    }
    
    return mini;
}

};
// @lc code=end


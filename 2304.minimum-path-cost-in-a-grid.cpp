/*
 * @lc app=leetcode id=2304 lang=cpp
 *
 * [2304] Minimum Path Cost in a Grid
 */

// @lc code=start
class Solution {
public:
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j, vector<vector<int>>& dp) {
    int row = grid.size();
    int col = grid[0].size();
    if (i == row - 1) {
        return grid[i][j];
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int minians = INT_MAX;
    int lookupx = grid[i][j]; // Get the current cell's value
    for (int k = 0; k < col; k++) {
        int temp = grid[i][j] + moveCost[lookupx][k] + solve(grid, moveCost, i + 1, k, dp);
        minians = min(temp, minians);
    }

    return dp[i][j] = minians;
}

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int n = grid[0].size();
    int minicost = INT_MAX;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < n; i++) {
        minicost = min(minicost, solve(grid, moveCost, 0, i, dp));
    }
    return minicost;
}



};
// @lc code=end


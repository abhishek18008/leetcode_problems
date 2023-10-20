 /*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
    int row = grid.size();
    int col = grid[0].size();

    // Base case: ball falls out of the bottom
    if (i == row) {
        return j;
    }

    // Ball gets stuck if it hits a wall or a "V" shaped pattern
    if (j < 0 || j >= col || grid[i][j] == -1 && (j == 0 || grid[i][j - 1] == 1) ||
        grid[i][j] == 1 && (j == col - 1 || grid[i][j + 1] == -1)) {
        return -1;
    }

    // Recursive calls for the two directions of redirection
    if (grid[i][j] == 1) {
        return solve(grid, i + 1, j + 1);
    } else {
        return solve(grid, i + 1, j - 1);
    }
}

vector<int> findBall(vector<vector<int>>& grid) {
    int col = grid[0].size();
    if (col == 1) {
        return { -1 };
    }

    vector<int> ans(col);
    for (int i = 0; i < col; i++) {
        int temp = solve(grid, 0, i);
        ans[i] = temp;
    }
    return ans;
}

};
// @lc code=end


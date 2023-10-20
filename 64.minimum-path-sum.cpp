/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        int row=grid.size();
        int col=grid[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        //base case
        if(i==row-1 && j==col-1) return grid[i][j];
        if(i==row || j==col)
        return INT_MAX; 

        int right=solve(grid,i+1,j,dp);
        int down=solve(grid,i,j+1,dp);
        return dp[i][j]=min(right,down)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,dp);
    }
};
// @lc code=end


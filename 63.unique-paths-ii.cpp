/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
int solve(int m,int n,int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1 )
        {
            if(obstacleGrid[i][j]!=1)
            return 1;
            else 
            return 0;
        }

        

        if(i>=m || j>=n)
        return 0;

        if(obstacleGrid[i][j]==1)
        return 0;

        if(dp[i][j]!=-1) return dp[i][j];


        int down=solve(m,n,i+1,j,dp,obstacleGrid);
        int right=solve(m,n,i,j+1,dp,obstacleGrid);
        return dp[i][j]= down+right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp,obstacleGrid);
        
    }
};
// @lc code=end


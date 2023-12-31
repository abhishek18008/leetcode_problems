/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int> &vec, int i, int j,vector<vector<int>> &dp){
        if(i+1 == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            ans = min(ans, vec[i]*vec[j]*vec[k] + solve(vec,i,k,dp) + solve(vec,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(values,0,n-1,dp);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    // int solve(vector<vector<int>>& triangle,int i,int j){
    //     int m=triangle.size();
    //     int n=triangle[i].size();
    //     //base case
    //     if(i==m)
    //     return 0;
    //     if(j>=n) return INT_MAX;
    //     int mini=INT_MAX;
    //     mini=min(mini,solve(triangle,i+1,j));
    //     mini=min(mini,solve(triangle,i+1,j+1));
    //     return mini+triangle[i][j];


    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        //solve iteratively
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];

    }
};
// @lc code=end


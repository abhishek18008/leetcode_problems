/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:

    int solve(vector<int>& nums1,vector<int>& nums2,int i,int j, vector<vector<int>>& dp){
        int n=nums1.size();
        int m=nums2.size();

        if(i==n || j==m)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //if values at i and j are same
        int takeit=INT_MIN;
        if(nums1[i]==nums2[j])
         takeit=solve(nums1,nums2,i+1,j+1,dp)+1;
        int ignorei=solve(nums1,nums2,i+1,j,dp);
        int ignorej=solve(nums1,nums2,i,j+1,dp);
        return dp[i][j]=max(takeit,max(ignorei,ignorej));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(nums1,nums2,0,0,dp);

    }
};

// @lc code=end


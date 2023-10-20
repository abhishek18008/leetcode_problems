/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
    
   

    int longestArithSeqLength(vector<int>& nums) {
     int n=nums.size();
     int res=0;
     vector<vector<int>> dp(n,vector<int>(1600,-1));
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d=nums[j]-nums[i]+501;
            dp[j][d] = max(2, dp[i][d] + 1);
            res = max(res, dp[j][d]);
        }
     }
     return res;

        
    }
};
// @lc code=end


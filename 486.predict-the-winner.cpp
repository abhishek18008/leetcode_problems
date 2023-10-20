/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& nums){
        //base case
        if(i>j) return 0;
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        //take i
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return dp[i][j]=max(take_i,take_j);

    }


    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));

        int total_score=accumulate(nums.begin(),nums.end(),0);
        int player1_score=solve(0,n-1,nums);
        int player2_score=total_score-player1_score;

        return player1_score>=player2_score;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:

    int solve(int amount,vector<int>& coins,int idx,vector<vector<int>>& dp){
        //base case
        
        if(idx==coins.size()|| amount<0) return 0;
        if(amount==coins[idx]) return 1;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        
        //take the coin at idx
        int take=solve(amount-coins[idx],coins,idx,dp);

        //don't take 
        int leave=solve(amount,coins,idx+1,dp);
        return dp[amount][idx]=take+leave;
    }
    
    int change(int amount, vector<int>& coins) {
        if (amount==0) return 1;
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,0,dp);
        
        
    }
};
// @lc code=end


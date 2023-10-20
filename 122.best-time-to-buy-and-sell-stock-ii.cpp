/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int> & prices,int index,int buy,vector<vector<int>>& dp){

        //base case
        int n=prices.size();
        if(index>=n){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy==1){
            int buytoday= -prices[index]+solve(prices,index+1,0,dp);
            int buylater=solve(prices,index+1,1,dp);
            return dp[index][buy]=max (buytoday,buylater);  
        }

        else{
            int ifselltoday=prices[index]+solve(prices,index+1,1,dp);
            int retaintoday=solve(prices,index+1,0,dp);
            return dp[index][buy]=max(ifselltoday,retaintoday);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int profit(vector<int>& prices, int fee, int buy, int index,vector<vector<int>>& dp) {
    // Base case
    int n = prices.size();
    if (index == n) {
        return 0;
    }
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }
    int maxi;
    if (buy == 1) {
        int ifselltoday = profit(prices, fee, 0, index + 1,dp);
        int sellotheday = profit(prices, fee, 1, index + 1,dp);
        maxi= max(ifselltoday - fee + prices[index], sellotheday);
    } else {
        int ifbuytoday = profit(prices, fee, 1, index + 1,dp);
        int buyotherday = profit(prices, fee, 0, index + 1,dp);
        maxi= max(ifbuytoday - prices[index], buyotherday);
    }
    dp[index][buy]=maxi;
    return maxi;
}

int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return profit(prices, fee, 0, 0,dp);
}

};
// @lc code=end


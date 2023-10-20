/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;       
        int minitilldate=prices[0];
        int maxProfit=INT_MIN;
        for(int i = 1; i < n; i++)
        {
            minitilldate=min(minitilldate,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minitilldate);
        }
        return maxProfit;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    
    // int solve(vector<int>& prices,int canbuy,int idx){
    //     //base case
    //     if(idx>=prices.size()){
    //         return 0;
    //     }
    //     if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];

    //     if(canbuy)
    //     return dp[idx][canbuy]=max(solve(prices,0,idx+1)-prices[idx],solve(prices,1,idx+1));

    //     else{
    //         //sell karna hai
    //         return dp[idx][canbuy]=max(solve(prices,1,idx+2)+prices[idx],solve(prices,0,idx+1));
    //     }
    
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp;
        dp.resize(n+2,vector<int>(2,0));
        
        //tabulation
       
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            dp[i][0]=max(dp[i+2][1]+prices[i],dp[i+1][0]);
        }
        return dp[0][1];

    }
};
// @lc code=end


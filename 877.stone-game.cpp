/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
    
    int solve(vector<int>& piles,int s,int e,vector<vector<int>>& dp){
        if(s==e-1){
            return max(piles[s],piles[e]);
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int ifleft=piles[s]+max(solve(piles,s+2,e,dp),solve(piles,s+1,e-1,dp));
        int ifright=piles[e]+max(solve(piles,s+1,e-1,dp),solve(piles,s,e-2,dp));

        return dp[s][e]=max(ifleft,ifright);

    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int s=0;
        int e=piles.size()-1;
        
        int alex = solve(piles,s,e,dp);
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];

        return alex > (sum - alex);
        
    }
};
// @lc code=end


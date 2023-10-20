/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public: 
    int total = 0;
    vector<vector<int>> dp;
    int solve(vector<int>& stones, int idx, int s1) {
        if (idx == stones.size()) return abs(2 * s1 - total); // Calculate the absolute difference here
        if(dp[idx][s1]!=-1) return dp[idx][s1];
        // If we include the idx to s1
        int pick = solve(stones, idx + 1, s1 + stones[idx]);
        // If we don't include the idx to s1
        int not_pick = solve(stones, idx + 1, s1);
        return dp[idx][s1]=min(pick, not_pick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        total = accumulate(stones.begin(), stones.end(), 0);
        dp.resize(n+1,vector<int>(total+1,-1));
        return solve(stones, 0, 0);
    }
};

// @lc code=end


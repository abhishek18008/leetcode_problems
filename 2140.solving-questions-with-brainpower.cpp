/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& questions,int idx){
        //base case
        if(idx>=questions.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        //solve this question
        long long _solve=solve(questions,idx+1+questions[idx][1])+questions[idx][0];

        //skip this question
        long long _skip=solve(questions,idx+1);
        return dp[idx]=max(_solve,_skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        dp.resize(n+1,-1);
        return solve(questions,0);
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=1911 lang=cpp
 *
 * [1911] Maximum Alternating Subsequence Sum
 */

// @lc code=start
class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll solve(vector<int>& nums,int idx,int parity){

        //base case
        if(idx==nums.size()) return 0;
        if(dp[idx][parity+1]!=-1) return dp[idx][parity+1];


        //select num at idx in subarray
        ll select=solve(nums,idx+1,-1*parity)+nums[idx]*parity;
        // leave the num at idx
        ll leave=solve(nums,idx+1,parity);
        return dp[idx][parity+1]=max(select,leave);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<ll>(3,-1));
        return solve(nums,0,1);
        
    }
};
// @lc code=end


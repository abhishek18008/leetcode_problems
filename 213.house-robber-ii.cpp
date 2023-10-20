/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums,int idx){
        int n=nums.size();  
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //choose the idx
        int choose=nums[idx]+solve(nums,idx+2);
        //don't choose the idx
        int skip=solve(nums,idx+1);
        return dp[idx]=max(choose,skip);
    }


    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        dp.resize(nums.size(),-1);
        int consider_last=solve(nums,1);
        nums.pop_back();
        dp.clear();
        int consider_first=solve(nums,0);
        return max(consider_first,consider_last);

    }
};
// @lc code=end


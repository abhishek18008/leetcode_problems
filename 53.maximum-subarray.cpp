/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(vector<int>& nums,int idx,bool mustpick){
    //     if(idx==nums.size()) return mustpick ? 0 : -1e5;  
    //     if(dp[idx][mustpick]!=-1) return dp[idx][mustpick];

    //     if(mustpick){
    //         int pick=solve(nums,idx+1,true)+nums[idx];
    //         return dp[idx][mustpick] =max(pick,0);
    //     }
        
    //     int pick=solve(nums,idx+1,true)+nums[idx];
    //     int leave=solve(nums,idx+1,false);
    //     return dp[idx][mustpick]=max(pick,leave);

    // }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         ans=max(ans,sum);
        //     }
        // }
        // return ans;
        // dp.resize(n+1,vector<int>(2,-1));
        // return solve(nums,0,false);
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(sum,ans);
            if(sum<0) sum=0;
        }
        return ans;

        
    }
};
// @lc code=end


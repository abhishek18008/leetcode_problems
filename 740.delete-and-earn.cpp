/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& freq, int idx){
        if(idx>=freq.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        //delete this 
        ans=max(ans,solve(freq,idx+2)+idx*freq[idx]);
        //leave this
        ans=max(ans,solve(freq,idx+1));
        return dp[idx]=ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        for(auto it:nums){
            freq[it]++;
        }
        dp.resize(maxi+1,-1);
        //now use dp on the freq matrix
        return solve(freq,1);

        //do iteratively 
        // vector<int> dp(maxi+3,0);
        // for(int i=maxi;i>0;i++){
        //     dp[i]=max(dp[i+2]+freq[i]*i, dp[i+1]);
        // }
        // return dp[1];



    }
};
// @lc code=end


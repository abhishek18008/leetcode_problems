/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start

class Solution {
public:
    int N,K;
    int mod= 1e9+7;
    vector<vector<int>> dp;
    int solve(int i,int target){
        if(i==0 && target!=0){
            return 0;
        }
        if(target==0 && i==0){
            return 1;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        long long ans=0;
        for(int j=1;j<=K && (target-j)>=0;j++){
            ans=(ans % mod+(solve(i-1,target-j))%mod)%mod;
        }
        return dp[i][target]=ans%mod;
    }


    int numRollsToTarget(int n, int k, int target) {
        N=n,K=k;
        
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(n,target);

        
    }
};
// @lc code=end


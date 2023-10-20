/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n,int *dp) {
        if(n==0 || n==1)
            return 1;
        
        if(dp[n]!=-1) 
            return dp[n];
        
        int maxi=0;
        
        for(int i=1;i<=n/2;i++){
            maxi=max(maxi,max(integerBreak(n-i,dp)*i,i*(n-i)));
        }
        
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        int *ans = new int[n+1];
		for(int j = 0; j <= n; j++) {
			ans[j] = -1;
		}
        return integerBreak(n,ans);
    }
};
// @lc code=end


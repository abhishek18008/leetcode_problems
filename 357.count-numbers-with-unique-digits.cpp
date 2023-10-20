/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        vector<int>dp(n+1,0);
        dp[1]=10;
        for(int i=2;i<=n;i++){
            int product=9*9;
            int k=i-2;
            int x=8;
            while(k--){
                product*=x;
                x--;
            }
            dp[i]=product+dp[i-1];

        }
        return dp[n];
    }
};
// @lc code=end


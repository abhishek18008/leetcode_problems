/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    // int N;
    // int solve(int n){
    //     if(n==0) return 0;
    //     if(n<0) return 1e8;
        
    //     //take 1,2,3,.. 
    //     //find ans of the rest of the solutions and takse minimum of them
    //     int mini=INT_MAX;
    //     for(int i=0;i<=sqrt(n) && n-i*i>=0;i++){
    //         mini=min(1+solve(n-i*i),mini);
    //     }
    //     return mini;
    // }
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int mini= INT_MAX;  
            for(int j=1;j*j<=i;j++){
                mini=min(mini,dp[i-j*j]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }
};
// @lc code=end


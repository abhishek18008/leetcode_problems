/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
public:
    vector<vector<double>> dp;
    double solve(int a,int b){
        //base case
        if(a<=0 && b<=0) return 0.5;
        if(a<=0 && b>0) return 1;
        if(a>0 && b<=0) return 0;
        if(dp[a][b]!=-1.0) return dp[a][b];
        //find the values for each of the 4 operations
        double o1=solve(a-100,b);
        double o2=solve(a-75,b-25);
        double o3=solve(a-50,b-50);
        double o4=solve(a-25,b-75);
        return dp[a][b]=0.25*(o1+o2+o3+o4);
    }
    double soupServings(int n) {
        if(n>5000) return 1;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
        
    }
};
// @lc code=end

